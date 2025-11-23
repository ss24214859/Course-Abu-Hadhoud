using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ContactsDataAccessLayer;

namespace ContactsBusinessLayer
{
    public class clsCountry
    {
        enum enMode { AddNew=0, Update=1};
        enMode Mode = enMode.AddNew;

        public int ID { get; set; }
        public string Name { get; set; }

        public string Code { get; set; } 
        public string PhoneCode { get; set; }


        private bool _AddNewCountry()
        {
            this.ID = clsCountryData.AddNewCountry(this.Name,this.Code,this.PhoneCode);
            return (ID != -1);
        }


        private bool _UpdateCountry()
        {
            return clsCountryData.UpdateCountry(this.ID, this.Name, this.Code, this.PhoneCode);
        }


        public clsCountry()
        {
            ID = -1;
            Name = "";
            Code = "";
            PhoneCode = "";
            Mode = enMode.AddNew;
        }

        public clsCountry(int countryID, string countryName ,string code , string phoneCode)
        {
            ID = countryID;
            Name = countryName;
            Code = code;
            PhoneCode = phoneCode;
            Mode = enMode.Update;
        }

        static public clsCountry Find(string CountryName)
        {
            int id = -1;
            string Code = "";
            string PhoneCode = "";
            if (clsCountryData.GetCountryByName(ref id,CountryName, ref Code,ref PhoneCode))
            {
                return  new clsCountry(id,CountryName, Code, PhoneCode);
            }
            return null;
        }

        static public clsCountry Find(int id)
        {
            string CountryName="";
            string Code = "";
            string PhoneCode = "";
            if (clsCountryData.GetCountryByID( id,ref CountryName, ref Code, ref PhoneCode))
            {
                return new clsCountry(id, CountryName, Code, PhoneCode);
            }
            return null;
        }

        static public bool IsExist (string CountryName)
        {
            return clsCountryData.IsCountryExistByName(CountryName);
        }

        static public bool Delete(int ID)
        {
            return clsCountryData.DeleteCountryByID(ID);
        }

        static public DataTable GetAllCountries()
        {
            return clsCountryData.GetAllCountries();
        }

        public bool Save()
        {
            switch (Mode)
            {
                case enMode.AddNew :

                    if(_AddNewCountry())
                    {
                        Mode = enMode.Update;
                        return true;
                    }
                    return false;

                case enMode.Update :

                    return _UpdateCountry();
                        
            }
            return false;

        }
    }
}
