#include <iostream>
#include <string>

class Passport {
protected:
    int id;
    int serialNumber;
    int citizenID;
    int birthYear;
    char gender;
    std::string firstName;
    std::string lastName;

public:
    Passport(int id, int serialNumber, int citizenID, int birthYear, char gender, const std::string& fName, const std::string& lName) : id(id), serialNumber(serialNumber), citizenID(citizenID), birthYear(birthYear), gender(gender), firstName(fName), lastName(lName)
    {
    }

    void showPassportInfo() const {
        std::cout << "First name: " << firstName << std::endl;
        std::cout << "Last name: " << lastName << std::endl;
        std::cout << "Passport ID: " << id << std::endl;
        std::cout << "Serial number: " << serialNumber << std::endl;
        std::cout << "Citizen ID: " << citizenID << std::endl;
        std::cout << "Birth year: " << birthYear << std::endl;
        std::cout << "Gender: " << (gender == 'M' ? "Male" : "Female") << std::endl;
    }
};

class ForeignPassport : public Passport {
private:
    int foreignPassportNumber;
    int visaCount;

public:
    ForeignPassport(int id, int serialNumber, int citizenID, int birthYear, char gender, const std::string& fName, const std::string& lName, int foreignPassportNumber, int visaCount) : Passport(id, serialNumber, citizenID, birthYear, gender, fName, lName), foreignPassportNumber(foreignPassportNumber), visaCount(visaCount) {}

    void showForeignPassportInfo() const {
        showPassportInfo();
        std::cout << "Foreign passport number: " << foreignPassportNumber << std::endl;
        std::cout << "Visa count: " << visaCount << std::endl;
    }
};

int main() {
    Passport p1(11111, 22222, 123456789, 2007, 'F', "Dariia", "Kuznetsova");
    std::cout << "Passport information: " << std::endl;
    p1.showPassportInfo();

    std::cout << std::endl;

    ForeignPassport fp1(11111, 22222, 123456789, 2007, 'F', "Dariia", "Kuznetsova", 54321, 2);
    std::cout << "Foreign passport information: " << std::endl;
    fp1.showForeignPassportInfo();

    return 0;
}
