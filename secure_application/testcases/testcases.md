# Hospital Management System - Test Cases

## TC-01 Patient Registration

Input:
Patient ID: P001
Name: Rahul
Age: 25
Disease: Fever

Expected:
Patient registered successfully.

## TC-02 Appointment

Input:
Patient ID: P001
Doctor: Dr. Sharma
Date: 20-09-2026

Expected:
Appointment created successfully.

## TC-03 Prescription

Input:
Patient ID: P001
Medicine: Paracetamol
Dosage: 500mg

Expected:
Prescription added successfully.

## TC-04 Billing

Input:
Patient ID: P001
Consultation: 500
Medicine: 200
Room: 1000

Expected:
Total bill = 1700.

## TC-05 Medical Record

Input:
Patient ID: P001

Expected:
Patient medical record displayed.

## TC-06 SQL Injection

Input:
SQL injection test input against the local test database.

Expected:
The vulnerable implementation demonstrates
that unsanitized input reaches the SQL query.

Vulnerability:
SQL Injection.

## TC-07 Broken Access Control

User:
P001

Requested record:
P002

Expected vulnerable behavior:
P001 can access P002's record.

Vulnerability:
Broken Access Control.

## TC-08 File Upload

Input:
A harmless test file.

Expected vulnerable behavior:
Application accepts the file without adequate
file validation.

Vulnerability:
File Upload Vulnerability.
