#include <iostream>

using namespace std;

void mass(double body_mass,double daily_req)
{
    double wgs,add_cals,t1,prot_coef,fats,B,T,W;
    cout<<endl<<"Weight gaining speed [%/month]: ";
    cin>>wgs;

    wgs/=100;
    t1=wgs*body_mass*7000;
    add_cals=((wgs*body_mass/4)*t1)/7;
    daily_req+=add_cals;

    cout<<endl<<"Proteins coefficient: ";
    cin>>prot_coef;
    B=prot_coef*body_mass;

    cout<<endl<<"Fats [%]: ";
    cin>>fats;
    fats/=100;
    T=fats*daily_req/9;

    W=(daily_req-(B*4+T*9))/4;

    cout<<endl<<"Kcal: "<<(int)daily_req<<endl;
    cout<<"B[g]: "<<(int)B<<endl;
    cout<<"T[g]: "<<(int)T<<endl;
    cout<<"W[g]: "<<(int)W<<endl;
}

void reduction(double body_mass,double daily_req)
{
    double wls,subb_cals,prot_coef,fats,B,T,W;
    cout<<endl<<"Weight loss speed [%/week]: ";
    cin>>wls;

    wls/=100;
    wls*=body_mass;
    subb_cals=wls*7000/7;
    daily_req-=subb_cals;

    cout<<endl<<"Proteins coefficient: ";
    cin>>prot_coef;
    B=prot_coef*body_mass;

    cout<<endl<<"Fats [%]: ";
    cin>>fats;

    fats/=100;
    T=fats*daily_req/9;

    W=(daily_req-(B*4+T*9))/4;

    cout<<endl<<"Kcal: "<<(int)daily_req<<endl;
    cout<<"B[g]: "<<(int)B<<endl;
    cout<<"T[g]: "<<(int)T<<endl;
    cout<<"W[g]: "<<(int)W<<endl;
}

int main()
{

    double body_mass,daily_req,act_coef;
    int choice;

    cout << "Total body mass [kg]: ";
    cin>>body_mass;

    cout<<endl<<"Multiplier: ";
    cin>>act_coef;

    daily_req=22*body_mass*act_coef;

    cout<<endl<<"Zero [kcal]: "<<daily_req<<endl;

    cout<<endl<<"1 -> Mass (high calories surplus)"<<endl;
    cout<<"2 -> Reduce fat (calories deficit)"<<endl;
    cout<<"What u wanna do: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        mass(body_mass,daily_req);
        break;

    case 2:
        reduction(body_mass,daily_req);
        break;

    default: return 0;
        break;
    }

    return 0;
}
