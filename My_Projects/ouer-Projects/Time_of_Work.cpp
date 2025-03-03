#include <iostream>
#include <cmath>
using namespace std;


/*1*/struct stPreparingWaist     //تحضير الكمر
{
    int ApplyWaist,
    ApplyStick ,
    LockStick ;
         
};


struct stZipper  //سوسته
{
    stTimeOfWork TimeOfWork;
};
struct stFlats    //فلتات
{
    stTimeOfWork TimeOfWork;
};

/*2*/struct stPreparingZipperFlats     //تحضير فلتات سوسته

{
    stZipper zipper;
    stFlats flats;

    stTimeOfWork TimeOfWork;
};



struct stShima        //شيمه صدر
{
    stTimeOfWork TimeOfWork;

};
struct stInstallZipperFlats    //تركيب فلتات السوسته
{
    stTimeOfWork TimeOfWork;

};
struct stInstallPocketFlats  //تركيب فلتات الجيب
{
    stTimeOfWork TimeOfWork;

};
struct stInstallPocketPaper  //تركيب ورق الجيب
{
    stTimeOfWork TimeOfWork;

};

/*3*/struct stPreparingFront     //تحضير الصدر
{
    stShima shima;

    stInstallZipperFlats InstallZipperFlates;
    stInstallPocketFlats InstallPocketFlats;

    stInstallPocketPaper InstallPocketPaper;

    stTimeOfWork TimeOfWork;


};



struct stInstallBackPocket  //تركيب جيب الظهر
{
    stTimeOfWork TimeOfWork;

};

/*4*/struct stPreparingBack     //تحضيرالظهر
{
    stShima Shima;
    stInstallBackPocket InstallBackPocket;

    stTimeOfWork TimeOfWork;

};



/*5*/ struct stShimaSides   //تشيم الجناب
{
    stShima Shima;

    stTimeOfWork TimeOfWork;

};



struct stFoldBackPockets  //طي الجيوب
{
    stTimeOfWork TimeOfWork;

};

struct stInstallInflatableStrip //تركيب شريط النفخ
{
    stTimeOfWork TimeOfWork;

};

/**/struct stPreparingSidePockets   //تحضير جيوب الجنب
{
    stFoldBackPockets FoldBackPockets;
    stInstallInflatableStrip InstallIflatableStrip;


    stTimeOfWork TimeOfWork;

};



struct stApllyFlips  //طبق القلابات
{
    stTimeOfWork TimeOfWork;
};

struct stHalfcm   //نص سنتي قلاب
{
    stTimeOfWork TimeOfWork;
};

/**/struct stPreparingFlips  //تحضير القلابات
{
    stApllyFlips ApllyFlips;
    stHalfcm Halfcm;

    stTimeOfWork TimeOfWork;
};

struct stInstallFlips  //تركيب القلابات
{
    stTimeOfWork TimeOfWork;
};

struct stInstallSidePocket   //تركيب جيب الجنب
{
    stTimeOfWork TimeOfWork;
};

struct stInstallInflatablePocket  //تركيب جيب المنفاخ
{
    stTimeOfWork TimeOfWork;
};


/**/struct stInstallSidePocketsAndFlips  //تركيب القلاب وجيب الجنب
{
    stInstallFlips InstallFlips;
    stInstallSidePocket InstallSidePocket;
    stInstallInflatablePocket InstallInflatablePocket;

    stTimeOfWork TimeOfWork;
};



/*6*/struct stSidePocketsAndFlips     //جيوب الجنب والقلابا
{
    stPreparingFlips PreparingFlips;
    stPreparingSidePockets PreparingSidePockets;
    stInstallSidePocketsAndFlips InstallSidePockersAndFlips;
    
    stTimeOfWork TimeOfWork;
};



/*7*/struct stInstallWaist
{
    stTimeOfWork TimeOfWork;
};



struct stFoldStick
{
    stTimeOfWork TimeOfWork;
};

/*8*/struct stFoldFoot
{
    stFoldStick FoldStick;

    stTimeOfWork TimeOfWork;
};


struct stPants    //مراحل البنطلون
{
    string name;
    stPreparingWaist PreparingWaist;
    stPreparingZipperFlats PreparingZipperFlats;
    stPreparingFront PrearingFront;
    stPreparingBack PreparingBack;
    stShimaSides ShimaSides;
    stSidePocketsAndFlips SidePocketsAndFlips;
    stInstallWaist InstallWaist;
    stFoldFoot FoldFoot;

    stTimeOfWork TimeOfWork;
};


int main()
{
   /* float Quantity;
    
    cin>> Quantity;*/
    stTimeOfWork time;cout<<"enter the Quantity to Calculat the time work ";
    stPants SchoolPant;
    cin>>SchoolPant.PreparingWaist.ApplyWaist.TimeOfWork.Time;
    
    
    SchoolPant.name="SchoolPants.";
    

    

    


    cout<<"the time of work is " <<SchoolPant.PreparingWaist.ApplyWaist.TApplyWaist;


    
    


}