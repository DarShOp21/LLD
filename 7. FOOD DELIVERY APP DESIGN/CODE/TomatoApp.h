#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include <vector>
#include <string>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"
using namespace std;

class TomatoApp {
public:
    TomatoApp() {
        initializeRestaurants();
    }

    

    void initializeRestaurants() {
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");

        restaurant1->addMenuItem(MenuItem("Chole Bhature", "P1", 120));
        restaurant1->addMenuItem(MenuItem("Samosa", "P2", 15));

    Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");

    restaurant2->addMenuItem(MenuItem("Raj Kachori", "P1", 80));
    restaurant2->addMenuItem(MenuItem("Pav Bhaji", "P2", 100));
    restaurant2->addMenuItem(MenuItem("Dhokla", "P3", 50));

    Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");

    restaurant3->addMenuItem(MenuItem("Masala Dosa", "P1", 90));
    restaurant3->addMenuItem(MenuItem("Idli Vada", "P2", 60));
    restaurant3->addMenuItem(MenuItem("Filter Coffee", "P3", 30));

    RestaurantManager* restaurantManager =
        RestaurantManager::getInstance();

    restaurantManager->addRestaurant(restaurant1);
    restaurantManager->addRestaurant(restaurant2);
    restaurantManager->addRestaurant(restaurant3);
    }


    vector<Restaurant*> searchRestaurants(const string& location) {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(User* user, Restaurant* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addToCart(User* user, const string& itemCode) {
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if (!restaurant) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item : restaurant->getMenu()) {
            if (item.getCode() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, const string& orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
        return nullptr;

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    

void payForOrder(User* user, Order* order) {
    if (order == nullptr) {
        cout << "Checkout failed: Cart is empty." << endl;
        return;
    }

    bool isPaymentSuccess = order->processPayment();

    if (isPaymentSuccess) {
        NotificationService::notify(order);
        user->getCart()->clear();
    }
}


    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getCode() << " : " << item.getName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotalCost() << endl;
    }
};

#endif // TOMATO_APP_H
