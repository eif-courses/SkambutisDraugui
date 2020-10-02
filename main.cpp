#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <regex>


struct Button {
    std::string name;
    Button(const std::string &name);
};
struct Person{
    int age;
    std::string vardas;
    void sokti(std::string vardas);


    Person(std::string v); // tik vardas
    Person(std::string vardas, int age); // vardas ir amzius

};
void Person::sokti(std::string vardas) {
  std::cout << vardas << " soka."<< std::endl;
}

Person::Person(std::string v):vardas(v) {
    std::cout << "Konstruktruktorius su vienu parametru!\n";
}

Person::Person(std::string vardas, int age):vardas(vardas), age(age) {
    std::cout << "Konstruktruktorius su dviem parametrais!\n";
}


struct Phone {
    std::string name;
    std::vector<Button> buttons;

    Phone(std::string name);

    void clickButton(std::string name);
    void grabPhone(Phone phone);

    void call(int number);

    void endCall();

    void leaveMessage(std::string message);

    void wait(int minutes);

};


bool isBusy();


void keliauti_apsipirkti(Person p){
    p.sokti(p.vardas);
    int result = p.age * 2;
    std::cout << p.vardas << std::endl;
}
void suma(int a, int b){
    a + b;
}

int main() {


   std::cout << "Labas aš esu krabas. Iš jūros Ą\n";

    Person petras("Petras");
    Person ona("Onute", 35);

    keliauti_apsipirkti(petras);
    keliauti_apsipirkti(ona);


   // std::cout <<





    std::srand(std::time(nullptr));

    Phone phone("Siemens");

    int input = 1;
    while (input != 0){
        std::cout << "-------------------------------------"<< std::endl;
        std::cout << "1. Grab Phone."<< std::endl;
        std::cout << "2. Enter phone number."<< std::endl;
        std::cout << "3. Call."<< std::endl;
        std::cout << "4. Wait."<< std::endl;
        std::cout << "5. Leave message."<< std::endl;
        std::cout << "0. Exit."<< std::endl;
        std::cout << "-------------------------------------"<< std::endl;
        std::cout << "Enter your choice:";
        std::cin >> input;

        switch (input) {
            case 0:
                break;
            case 1:
                phone.grabPhone(phone);
                break;
            case 2:
                phone.clickButton("4");
                break;
            case 3:
                //phone.call();
                break;
            case 4:
                phone.wait(5);
                break;
            case 5:
                phone.leaveMessage("Hello");
                break;
            default:
                std::cout << "Bloga ivestis pasirinkite nuo 0 iki 5";
                break;
        }



    }






    std::cout << "Hello, World!" << std::endl;
    return 0;
}

Button::Button(const std::string &name) : name(name) {

}

Phone::Phone(std::string name) : name(name) {
    for (int i = 0; i < 10; i++) {
        Button btn(std::to_string(i));
        buttons.push_back(btn);
    }
}

void Phone::clickButton(std::string name) {

    for (Button btn: buttons) {
        if (btn.name == name) {
            std::cout << "Digit pressed: " << name << std::endl;
        }
    }
}

void Phone::grabPhone(Phone phone) {
    std::cout << "Picked phone: " << phone.name << std::endl;
    int input = 0;
    std::cout << "Enter phone number:";

    //waeweawjejawe
    // regex(wawewadea) -> tik skaicius 0-9
    std::cin >> input;

    call(input);

}

void Phone::call(int number) {
    std::cout << "Calling..." << number<<std::endl;
    if(isBusy()){
        wait(5);
    }else{
        std::cout << "Call success! Friend Happy!" <<std::endl;
    }

}

void Phone::endCall() {

}

void Phone::leaveMessage(std::string message) {

}

void Phone::wait(int minutes) {
    std::cout << "waiting...." << minutes<< std::endl;
    //call();
}

bool isBusy() {
    return std::rand() % 10;
}

