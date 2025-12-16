#include <iostream>

enum Element {FIRE, ICE, EARTH, WIND};

class Spell{
    private:
        std::string name;
        int power;
        Element type;

    public:
        Spell(){
            this->name = "Unknown";
            this->power = 1;
            this->type = WIND;
        }

        Spell(std::string name, int power, Element type){
            this->name = name;
            this->power = power;
            this->type = type;
        }

        std::string getName(){
            return name;
        }
        int getPower(){
            return power;
        }
        Element getType(){
            return type;
        }
        void setName(std::string name){
            this->name = name;
        }
        void setPower(int power){
            if (power < 0){
                this->power = 0;
                std::cout << "Error: Negative power not allowed. Power set to 0 \n";
            }
            else{
                this->power = power;
            }
        }
        void setType(Element type){
            this->type = type;
        }
};

class HealingSpell : public Spell{
    private:
        int healAmount;

    public:
        HealingSpell(std::string name, int power, Element type, int healAmount){
            this->setName(name);
            this->setPower(power);
            this->setType(type);
            this->healAmount = healAmount;
        }
        
        int getHealAmount(){
            return healAmount;
        }
        void setHealAmount(int healAmount){
            this->healAmount = healAmount;
        }
};

void announce_spell(Spell spell){
    std::cout << "Scanning " << spell.getName() << " ... Power Level: " << spell.getPower() << '\n';
}

int main(){

    // --- Part 1 ---
    Spell fireball;
    fireball.setPower(50);
    fireball.setType(FIRE);

    std::cout << "The power of fireball is " << fireball.getPower() << '\n';
    std::cout << "The type of fireball is " << fireball.getType() << '\n';
    
    // --- Part 2 ---
    Spell defaultSpell;
    Spell iceSpike;
    iceSpike.setName("Ice Spike");
    iceSpike.setPower(45);
    iceSpike.setType(ICE);
    
    std::cout << "The power of defaultSpell is " << defaultSpell.getPower() << '\n';
    std::cout << "The type of defaultSpell is " << defaultSpell.getPower() << '\n';
    
    std::cout << "The power of iceSpike is " << iceSpike.getPower() << '\n';
    std::cout << "The type of iceSpike is " << iceSpike.getType() << '\n';
    
    // --- Part 3 ---
    fireball.setPower(-18);
    
    // --- Part 4 ---
    HealingSpell restoration("Holy Light", 10, EARTH, 20);
    std::cout << "The name of restoration is " << restoration.getName() << '\n';
    std::cout << "The heal amount of restoration is " << restoration.getHealAmount() << '\n';
    
    // --- Final Part ---
    announce_spell(iceSpike);
    announce_spell(restoration);
    
    iceSpike.setPower(100);
    std::cout << "The power of iceSpike is " << iceSpike.getPower() << '\n';

    return 0;
}