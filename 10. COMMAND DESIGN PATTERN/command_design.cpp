

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Light {
public:
    void on() {
        cout << "LIGHT TURNED ON\n";
    }

    void off() {
        cout << "LIGHT TURNED OFF\n";
    }
};

class Fan {
public:
    void on() {
        cout << "FAN TURNED ON\n";
    }

    void off() {
        cout << "FAN TURNED OFF\n";
    }
};

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class LightCommand : public Command {
private:
    Light* light;

public:
    LightCommand(Light* l) : light(l) {}

    void execute() override {
        light->on();
    }

    void undo() override {
        light->off();
    }
};

class FanCommand : public Command {
private:
    Fan* fan;

public:
    FanCommand(Fan* f) : fan(f) {}

    void execute() override {
        fan->on();
    }

    void undo() override {
        fan->off();
    }
};

class RemoteController {
private:
    static constexpr int numButtons = 3;

    vector<unique_ptr<Command>> buttons;
    bool buttonPressed[numButtons];

public:
    RemoteController() : buttons(numButtons) {
        for (int i = 0; i < numButtons; i++) {
            buttonPressed[i] = false;
        }
    }

    void setCommand(int idx, unique_ptr<Command> cmd) {
        if (idx >= 0 && idx < numButtons) {
            buttons[idx] = move(cmd);
            buttonPressed[idx] = false;
        }
    }

    void pressButton(int idx) {
        if (idx >= 0 && idx < numButtons && buttons[idx] != nullptr) {

            if (!buttonPressed[idx]) {
                buttons[idx]->execute();
            } else {
                buttons[idx]->undo();
            }

            buttonPressed[idx] = !buttonPressed[idx];

        } else {
            cout << "No command assigned at button "
                 << idx << endl;
        }
    }
};

int main() {

    Light livingRoomLight;
    Fan ceilingFan;

    RemoteController remote;

    remote.setCommand(0, make_unique<LightCommand>(&livingRoomLight));
    remote.setCommand(1, make_unique<FanCommand>(&ceilingFan));

    cout << "--- Toggling Light Button 0 ---\n";
    remote.pressButton(0);
    remote.pressButton(0);

    cout << "--- Toggling Fan Button 1 ---\n";
    remote.pressButton(1);
    remote.pressButton(1);

    cout << "--- Pressing Unassigned Button 2 ---\n";
    remote.pressButton(2);

    return 0;
}

