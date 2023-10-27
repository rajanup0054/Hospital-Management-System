#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct Patient {
    std::string name;
    int age;
    std::string doctor;
};

std::vector<Patient> patients;

void addPatient() {
    Patient patient;
    std::cout << "Enter patient name: ";
    std::cin >> patient.name;
    std::cout << "Enter patient age: ";
    std::cin >> patient.age;
    std::cout << "Enter doctor's name: ";
    std::cin >> patient.doctor;
    patients.push_back(patient);
    std::cout << "Patient information added successfully." << std::endl;
}

void assignPatientToDoctor() {
    if (patients.empty()) {
        std::cout << "No patients available to assign to a doctor." << std::endl;
        return;
    }

    std::cout << "Available Doctors: ";
    std::vector<std::string> availableDoctors;
    for (const Patient& patient : patients) {
        if (std::find(availableDoctors.begin(), availableDoctors.end(), patient.doctor) == availableDoctors.end()) {
            availableDoctors.push_back(patient.doctor);
            std::cout << patient.doctor << " ";
        }
    }
    std::cout << std::endl;

    std::string doctorName;
    std::cout << "Enter the doctor's name: ";
    std::cin >> doctorName;

    bool doctorFound = false;
    for (Patient& patient : patients) {
        if (patient.doctor == doctorName) {
            doctorFound = true;
            std::cout << "Assigning patient to " << doctorName << " doctor." << std::endl;
            // Implement patient assignment logic here.
        }
    }

    if (!doctorFound) {
        std::cout << "Doctor not found in the records." << std::endl;
    }
}

void editPatientInformation() {
    if (patients.empty()) {
        std::cout << "No patients available to edit." << std::endl;
        return;
    }

    std::string patientName;
    std::cout << "Enter the name of the patient to edit: ";
    std::cin >> patientName;

    for (Patient& patient : patients) {
        if (patient.name == patientName) {
            std::cout << "Enter new patient name: ";
            std::cin >> patient.name;
            std::cout << "Enter new patient age: ";
            std::cin >> patient.age;
            std::cout << "Enter new doctor's name: ";
            std::cin >> patient.doctor;
            std::cout << "Patient information updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Patient not found in the records." << std::endl;
}

void displayPatientInformation() {
    if (patients.empty()) {
        std::cout << "No patients available to display." << std::endl;
        return;
    }

    std::string patientName;
    std::cout << "Enter the name of the patient to display: ";
    std::cin >> patientName;

    for (const Patient& patient : patients) {
        if (patient.name == patientName) {
            std::cout << "Patient Name: " << patient.name << std::endl;
            std::cout << "Patient Age: " << patient.age << std::endl;
            std::cout << "Doctor's Name: " << patient.doctor << std::endl;
            return;
        }
    }

    std::cout << "Patient not found in the records." << std::endl;
}

void deletePatientInformation() {
    if (patients.empty()) {
        std::cout << "No patients available to delete." << std::endl;
        return;
    }

    std::string patientName;
    std::cout << "Enter the name of the patient to delete: ";
    std::cin >> patientName;

    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->name == patientName) {
            patients.erase(it);
            std::cout << "Patient information deleted successfully." << std::endl;
            return;
        }
    }

    std::cout << "Patient not found in the records." << std::endl;
}

int main() {
    int choice;
    do {
        std::cout << "\nHospital Management System\n";
        std::cout << "1. Add New Patient's Information\n";
        std::cout << "2. Assign a Patient to a Doctor\n";
        std::cout << "3. Edit Patient's Information\n";
        std::cout << "4. Display Patient's Information\n";
        std::cout << "5. Delete Patient's Information\n";
        std::cout << "6. Number of Patients in the Hospital\n";
        std::cout << "7. Delete All the Contents in the Database\n";
        std::cout << "8. Display the Details of All the Patients in the Hospital\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                assignPatientToDoctor();
                break;
            case 3:
                editPatientInformation();
                break;
            case 4:
                displayPatientInformation();
                break;
            case 5:
                deletePatientInformation();
                break;
            case 6:
                std::cout << "Number of Patients in the Hospital: " << patients.size() << std::endl;
                break;
            case 7:
                patients.clear();
                std::cout << "All contents in the database have been deleted." << std::endl;
                break;
            case 8:
                // Display all patients
                for (const Patient& patient : patients) {
                    std::cout << "Name: " << patient.name << ", Age: " << patient.age << ", Doctor: " << patient.doctor << std::endl;
                }
                break;
            case 9:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}
