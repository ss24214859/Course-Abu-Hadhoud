using ContactsDataAccessLayer;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Net;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace ContactsBusinessLayer
{
    public class clsContact
    {
        
        enum enMode { AddNew = 0 , Update = 1 };
        enMode Mode = enMode.AddNew;

        public int ID { get; set; }
        public string FirstName { set; get; }
        public string LastName { set; get; }
        public string Email { set; get; }
        public string Phone { set; get; }
        public string Address { set; get; }
        public DateTime DateOfBirth { set; get; }
        public int CountryID { set; get; }
        public string ImagePath {  set; get; }

        
        public clsContact()
        {

            ID          = -1;
            FirstName   = "";
            LastName    = "";
            Email       = "";
            Phone       = "";
            Address     = "";
            DateOfBirth = DateTime.Now;
            CountryID   = -1;
            ImagePath = "";

            Mode = enMode.AddNew;
        }
        public clsContact(int ID, string FirstName, string LastName, string Email,
            string Phone, string Address, DateTime DateOfBirth, int CountryID, string ImagePath)
        {
            this.ID = ID;
            this.FirstName = FirstName;
            this.LastName = LastName;
            this.Email = Email;
            this.Phone = Phone;
            this.Address = Address;
            this.DateOfBirth = DateOfBirth;
            this.CountryID = CountryID;
            this.ImagePath = ImagePath;

            Mode = enMode.Update;
        }
        private bool _AddNewContact()
        {
            this.ID = clsContactData.AddNewContact(this.FirstName, this.LastName, this.Email,
                this.Phone,this.Address,this.DateOfBirth,this.CountryID,this.ImagePath);

            return (this.ID != -1);
        }

        private bool _UpdateContact()
        {
            return clsContactData.UpdateContact(this.ID, this.FirstName, this.LastName, this.Email,
                        this.Phone, this.Address, this.DateOfBirth, this.CountryID, this.ImagePath);
        }


        public static clsContact Find(int ID)
        {
            string FirstName ="" , LastName ="" , Email ="" , Phone ="" , Address ="" ;
            DateTime DateOfBirth = DateTime.Now;
            int CountryID=-1;
            string ImagePath ="" ;
            if (clsContactData.GetContactInfoByID(ID, ref FirstName, ref LastName, ref Email, ref Phone, ref Address, ref DateOfBirth, ref CountryID, ref ImagePath))
                return new clsContact(ID, FirstName, LastName, Email, Phone, Address, DateOfBirth, CountryID, ImagePath);
            else 
                return null;
        }

        public static bool Delete(int ID)
        {
            return (clsContactData.DeleteContactByID(ID));
        }

        public static DataTable GetAllContacts()
        {
            return clsContactData.GetAllContacts();
        }
        public static bool IsContactExist(int ContactID)
        {
            return clsContactData.IsContactExistByID(ContactID);
        }

        public bool Save()
        {
            switch (Mode)
            {
                case enMode.AddNew:
                    if(_AddNewContact())
                    {
                        Mode = enMode.Update;
                        return true;
                    }
                    else
                    return false;
                case enMode.Update:
                    return _UpdateContact();
            }
            return false;
        }


        
    }
}
