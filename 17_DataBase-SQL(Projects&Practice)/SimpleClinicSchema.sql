CREATE TABLE "Person"(
    "PersonID" INT NOT NULL,
    "Name" NVARCHAR(100) NOT NULL,
    "DateOfBirth" DATE NOT NULL,
    "Gender" NVARCHAR(1) NOT NULL,
    "PhoneNumber" NVARCHAR(20) NOT NULL,
    "Email" NVARCHAR(200) NULL,
	Primary Key (PersonID)
);

CREATE TABLE "Patient"(
    "PatientID" INT NOT NULL,
    "PersonID" INT NOT NULL
	 PRIMARY KEY("PatientID")
);

CREATE UNIQUE INDEX "patient_personidbigint_unique" ON
    "Patient"("PersonID");
CREATE TABLE "Doctor"(
    "DoctorID" INT NOT NULL,
    "PersonID" INT NOT NULL,
    "Specialization" NVARCHAR(100) NOT NULL
);
ALTER TABLE
    "Doctor" ADD CONSTRAINT "doctor_doctorid_primary" PRIMARY KEY("DoctorID");
CREATE UNIQUE INDEX "doctor_personid_unique" ON
    "Doctor"("PersonID");

---------------------------------/


CREATE TABLE "Appointment"(
    "AppointmentID" INT NOT NULL,
    "DoctorID" INT NOT NULL,
    "PatientID" INT NOT NULL,
    "AppointmentDateAndTime" DATETIME NOT NULL,
    "AppointmentStatus" TINYINT NOT NULL,
    "MedicalRecordID" INT NOT NULL,
    "PaymentID" INT NOT NULL
);
ALTER TABLE
    "Appointment" ADD CONSTRAINT "appointment_appointmentid_primary" PRIMARY KEY("AppointmentID");
CREATE UNIQUE INDEX "appointment_medicalrecordid_unique" ON
    "Appointment"("MedicalRecordID");
CREATE UNIQUE INDEX "appointment_paymentid_unique" ON
    "Appointment"("PaymentID");
CREATE TABLE "MedicalRecord"(
    "MedicalRecordID" INT NOT NULL,
    "VisitDescription" NVARCHAR(200) NULL,
    "Diagonsis" NVARCHAR(200) NOT NULL,
    "AdditionalNotes" NVARCHAR(255) NULL
);
ALTER TABLE
    "MedicalRecord" ADD CONSTRAINT "medicalrecord_medicalrecordid_primary" PRIMARY KEY("MedicalRecordID");
CREATE TABLE "Prescription"(
    "PrescriptionID" INT NOT NULL,
    "MedicalRecordID" INT NOT NULL,
    "MedicationName" NVARCHAR(100) NOT NULL,
    "dosage" NVARCHAR(200) NOT NULL,
    "Frequency" NVARCHAR(50) NOT NULL,
    "StartDate" DATE NOT NULL,
    "EndDate" DATE NOT NULL,
    "SpecialInstructions" NVARCHAR(200) NULL
);
ALTER TABLE
    "Prescription" ADD CONSTRAINT "prescription_prescriptionid_primary" PRIMARY KEY("PrescriptionID");
Create Unique Index "Prescription_MedicalRecordID_Unique" ON Prescription("MedicalRecordID")

CREATE TABLE "Payment"(
    "PaymentID" INT NOT NULL,
    "PaymentDate" DATE NOT NULL,
    "PaymentMethod" NVARCHAR(50) NOT NULL,
    "AmountPaid" DECIMAL(8, 2) NOT NULL,
    "AdditionalNotes" NVARCHAR(200) NOT NULL
);
ALTER TABLE
    "Payment" ADD CONSTRAINT "payment_paymentid_primary" PRIMARY KEY("PaymentID");
ALTER TABLE
    "Doctor" ADD CONSTRAINT "doctor_personid_foreign" FOREIGN KEY("PersonID") REFERENCES "Person"("PersonID");
ALTER TABLE
    "Patient" ADD CONSTRAINT "patient_personid_foreign" FOREIGN KEY("PersonID") REFERENCES "Person"("PersonID");
ALTER TABLE
    "Appointment" ADD CONSTRAINT "appointment_medicalrecordid_foreign" FOREIGN KEY("MedicalRecordID") REFERENCES "MedicalRecord"("MedicalRecordID");
ALTER TABLE
    "Prescription" ADD CONSTRAINT "prescription_medicalrecordid_foreign" FOREIGN KEY("MedicalRecordID") REFERENCES "MedicalRecord"("MedicalRecordID");
ALTER TABLE
    "Appointment" ADD CONSTRAINT "appointment_doctorid_foreign" FOREIGN KEY("DoctorID") REFERENCES "Doctor"("DoctorID");
ALTER TABLE
    "Appointment" ADD CONSTRAINT "appointment_paymentid_foreign" FOREIGN KEY("PaymentID") REFERENCES "Payment"("PaymentID");
ALTER TABLE
    "Appointment" ADD CONSTRAINT "appointment_patientid_foreign" FOREIGN KEY("PatientID") REFERENCES "Patient"("PatientID");