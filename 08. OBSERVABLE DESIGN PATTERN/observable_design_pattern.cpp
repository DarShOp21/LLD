#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ISubscriber{
  public:
    virtual void update() = 0;
    virtual ~ISubscriber(){}
};

class IChannel{
  public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel(){}
};

class Channel : public IChannel{
  public:
    vector<ISubscriber*> subscribers;
    string name;
    string latest_video;

  public:
    Channel(const string& name){
      this->name = name;
    }

    void subscribe(ISubscriber *subscriber) override{
      if(find(subscribers.begin(),subscribers.end(),subscriber) == subscribers.end()){
        subscribers.push_back(subscriber);
      }
    }

    void unsubscribe(ISubscriber *subscriber) override{
      auto sub = find(subscribers.begin(),subscribers.end(),subscriber);
      if(sub!=subscribers.end())
        subscribers.erase(sub);
      else
        cout << "Subscriber not present";
    }

    void notifySubscribers() override{
      for(ISubscriber* sub : subscribers)
        sub->update();
    }

    void uploadVideo(const string& vid_title){
      latest_video = vid_title;
      cout << "\n[" << name << " uploaded \"" << vid_title << "\"]\n";
      notifySubscribers();
    }

    string getVideoData(){
      return "\nCheckout our new Video : " + latest_video + "\n";
    }
};

class Subscriber : public ISubscriber{
  private:
    string name;
    Channel* channel;

  public:
    Subscriber(const string& name , Channel* channel){
      this->name = name;
      this->channel = channel;
    }

    void update() override{
      cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};

int main() {
    // Create a channel and subscribers
    Channel* channel = new Channel("CoderArmy");

    Subscriber* subs1 = new Subscriber("Varun", channel);
    Subscriber* subs2 = new Subscriber("Tarun", channel);

    // Varun and Tarun subscribe to CoderArmy
    channel->subscribe(subs1);
    channel->subscribe(subs2);

    // Upload a video: both Varun and Tarun are notified
    channel->uploadVideo("Observer Pattern Tutorial");

    // Varun unsubscribes; Tarun remains subscribed
    channel->unsubscribe(subs1);

    // Upload another video: only Tarun is notified
    channel->uploadVideo("Decorator Pattern Tutorial");

    return 0;
}
