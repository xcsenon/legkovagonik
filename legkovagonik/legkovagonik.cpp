#include <iostream>
#include <string>
#include <vector>

// Flyweight interface
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
};

// ConcreteFlyweight
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "ConcreteFlyweight with Intrinsic State: " << intrinsicState
            << " and Extrinsic State: " << extrinsicState << std::endl;
    }

    const std::string& getIntrinsicState() const {
        return intrinsicState;
    }
};

// FlyweightFactory
class FlyweightFactory {
private:
    std::vector<ConcreteFlyweight*> flyweights;

public:
    Flyweight* getFlyweight(const std::string& key) {
        for (auto flyweight : flyweights) {
            if (flyweight->getIntrinsicState() == key) {
                return flyweight;
            }
        }

        ConcreteFlyweight* newFlyweight = new ConcreteFlyweight(key);
        flyweights.push_back(newFlyweight);
        return newFlyweight;
    }
};

int main() {
    FlyweightFactory flyweightFactory;

    Flyweight* flyweight1 = flyweightFactory.getFlyweight("shared");
    flyweight1->operation("A");

    Flyweight* flyweight2 = flyweightFactory.getFlyweight("shared");
    flyweight2->operation("B");

    Flyweight* flyweight3 = flyweightFactory.getFlyweight("unique");
    flyweight3->operation("C");

    return 0;
}
