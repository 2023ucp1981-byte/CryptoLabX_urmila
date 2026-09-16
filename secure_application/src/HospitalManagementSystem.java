import java.util.*;

public class HospitalManagementSystem {

    static Scanner scanner = new Scanner(System.in);

    static ArrayList<String> patients = new ArrayList<>();
    static ArrayList<String> appointments = new ArrayList<>();
    static ArrayList<String> prescriptions = new ArrayList<>();

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n========================================");
            System.out.println("       HOSPITAL MANAGEMENT SYSTEM");
            System.out.println("========================================");
            System.out.println("1. Patient Registration");
            System.out.println("2. Appointment Management");
            System.out.println("3. Prescription Management");
            System.out.println("4. Billing");
            System.out.println("5. Medical Records");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");

            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    registerPatient();
                    break;

                case "2":
                    manageAppointment();
                    break;

                case "3":
                    managePrescription();
                    break;

                case "4":
                    billing();
                    break;

                case "5":
                    medicalRecords();
                    break;

                case "6":
                    System.out.println("Exiting Hospital Management System...");
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }

    // 1. Patient Registration
    static void registerPatient() {

        System.out.println("\n===== Patient Registration =====");

        System.out.print("Enter Patient ID: ");
        String id = scanner.nextLine();

        System.out.print("Enter Patient Name: ");
        String name = scanner.nextLine();

        System.out.print("Enter Age: ");
        String age = scanner.nextLine();

        System.out.print("Enter Disease: ");
        String disease = scanner.nextLine();

        String patient = "ID: " + id
                + ", Name: " + name
                + ", Age: " + age
                + ", Disease: " + disease;

        patients.add(patient);

        System.out.println("\nPatient registered successfully!");
    }

    // 2. Appointment Management
    static void manageAppointment() {

        System.out.println("\n===== Appointment Management =====");

        System.out.print("Enter Patient ID: ");
        String patientId = scanner.nextLine();

        System.out.print("Enter Doctor Name: ");
        String doctor = scanner.nextLine();

        System.out.print("Enter Appointment Date: ");
        String date = scanner.nextLine();

        String appointment = "Patient ID: " + patientId
                + ", Doctor: " + doctor
                + ", Date: " + date;

        appointments.add(appointment);

        System.out.println("\nAppointment created successfully!");
    }

    // 3. Prescription Management
    static void managePrescription() {

        System.out.println("\n===== Prescription Management =====");

        System.out.print("Enter Patient ID: ");
        String patientId = scanner.nextLine();

        System.out.print("Enter Medicine: ");
        String medicine = scanner.nextLine();

        System.out.print("Enter Dosage: ");
        String dosage = scanner.nextLine();

        String prescription = "Patient ID: " + patientId
                + ", Medicine: " + medicine
                + ", Dosage: " + dosage;

        prescriptions.add(prescription);

        System.out.println("\nPrescription added successfully!");
    }

    // 4. Billing
    static void billing() {

        System.out.println("\n===== Hospital Billing =====");

        try {
            System.out.print("Enter Patient ID: ");
            String patientId = scanner.nextLine();

            System.out.print("Enter Consultation Fee: ");
            double consultation = Double.parseDouble(scanner.nextLine());

            System.out.print("Enter Medicine Charges: ");
            double medicine = Double.parseDouble(scanner.nextLine());

            System.out.print("Enter Room Charges: ");
            double room = Double.parseDouble(scanner.nextLine());

            double total = consultation + medicine + room;

            System.out.println("\n========== BILL ==========");
            System.out.println("Patient ID: " + patientId);
            System.out.println("Consultation: " + consultation);
            System.out.println("Medicine: " + medicine);
            System.out.println("Room: " + room);
            System.out.println("Total: " + total);
            System.out.println("==========================");

        } catch (NumberFormatException e) {
            System.out.println("Invalid amount entered.");
        }
    }

    // 5. Medical Records
    static void medicalRecords() {

        System.out.println("\n===== Medical Records =====");

        System.out.print("Enter Patient ID: ");
        String patientId = scanner.nextLine();

        System.out.println("\nSearching medical records for: " + patientId);

        boolean found = false;

        for (String patient : patients) {
            if (patient.contains("ID: " + patientId)) {
                System.out.println("\nPatient Record:");
                System.out.println(patient);
                found = true;
            }
        }

        for (String prescription : prescriptions) {
            if (prescription.contains("Patient ID: " + patientId)) {
                System.out.println("Prescription:");
                System.out.println(prescription);
            }
        }

        if (!found) {
            System.out.println("No patient record found.");
        }
    }
}
