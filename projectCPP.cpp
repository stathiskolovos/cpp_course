// �������		������������	5714
// ���������	�������			5793
// ��������		��������		5933

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <iomanip> 

using namespace std;

// ��������� ��� ����� KRATHSH ���� ��� ��� ����� DWMATIO,
// ����� �� �������������� �' ���� ��� �����.

class KRATHSH;

class DWMATIO
{  
// ���� ��� ��� ����� DWMATIO
private:
	int ID;  
    int hwrhtikothta;  
    double TimhAnaAtomo;  

public:
    static int room_id; //������� ��������
    // ������� �� pointers ���� ����������� ����� KRATHSH
    KRATHSH *PIN_DIATH[30];  
 
 // �������
 
 // �������� ������������� �� �� keyword virtual,
 // ��� �� ��������� ���� �������� ��� �������-������� ��� DWMATIO
 // �� ���������� ��' ��� ���������� ����� ��� ������������ ����
 
    DWMATIO(int No_Atomwn, double PosoAnaAtomo);
    virtual bool Nea_Krathsh(KRATHSH *K);
    virtual double Timologhsh();
    virtual bool Akurwsh(int ID_Value);
    virtual double Plhrothta();
	
	int get_ID();
	int get_hwrhtikothta();
	int get_TimhAnaAtomo();

};


class KRATHSH
{
	private:
		int ID;
		string Onoma_Pelath;
		int Afixh;
		int Meres_Diamonhs;
		int Arithmos_atomwn;
    public:
    	DWMATIO *Dwmatio; 
    static int room_id; 
   
    // �������
    KRATHSH(); 
    
    KRATHSH(string onoma_pel, int mera, int meres_diam, int N); 
	// ������� ������������ DWMATIO ��� ��������� Dwmatio ��� ��������
	void set_room(DWMATIO *R);
	// ������� ���� ���� ������� ��� ����� KRATHSH,
	// � ������� �� ����� ��� ����������� �����������
    void get_Krathsh_info();
    // ������� ��� ��������� ��� ����������� ��� ��������
    void Print();
	
	// ������� ��� ����������� ��� ����� ��� ����������
	int get_ID();
	int get_Afixh();
	int get_Meres_Diamonhs();
	int get_Arithmos_atomwn();
    string  get_Onoma_Pelath();
    
};

// ����� DWMATIO_A ��� ���������� ��� ����� DWMATIO
class DWMATIO_A : public DWMATIO
{
	private:
		double TimhAnaMera;

	public:
	// �������	
     DWMATIO_A(int No_Atomwn, double PosoAnaAtomo);
     double Timologhsh();
	 int get_TimhAnaMera();
	 
};

// ����� DWMATIO_B ��� ���������� ��� ����� DWMATIO_A
class DWMATIO_B : public DWMATIO_A
{
	private:
		double EkptwshAnaMera;

	public:
	// �������	
	 DWMATIO_B(int No_Atomwn, double TimhAnaMera,double Ekptwsh);
     double Timologhsh();
	 bool Akurwsh(int ID_Value);
     int get_EkptwshAnaMera(); 
};

// ����� DWMATIO_C ��� ���������� ��� ����� DWMATIO
class DWMATIO_C : public DWMATIO {
	
	private:
		int ElahistaAtoma;
		int ElahistesMeres;
	
    public:

// �������
DWMATIO_C(int No_Atomwn, double TimhAnaAtomo2,int elaxAtom, int elaxMeres);
  bool Nea_Krathsh(KRATHSH *K);
   int get_ElahistaAtoma(); 
   int get_ElahistesMeres(); 

};


class HOTEL
{
private:
 string HotelName;
  
public:
    vector<DWMATIO *> Dwmatia;  
    vector<KRATHSH *> Krathseis;  
 
 	// �������  
    HOTEL(string hotelname);
    void add_Room(DWMATIO *D1);
    DWMATIO* Search_Room(int ID_Value);
    KRATHSH* Search_Krathsh(int ID_Value);
	bool linkKrathshRoom(KRATHSH *K, int ID_Value);
	int add_Krathsh(KRATHSH *K);
    bool Akurwsh(int ID_Value);
    double Ypologismos_Esodwn(int ID_Value);
    double Ypologismos_Esodwn();
    void Print_Plano();
    void Print_Krathseis();
    void Print_Dwmatia();
};


// ������������ �������� ��� id �������� ��� ���������

int DWMATIO::room_id=100;
int KRATHSH::room_id=1;

	// ����� ���������� KRATHSH() ���� �� ��� ����� KRATHSH
	// ��� ������� ���� ������ ��������

    KRATHSH::KRATHSH()
    {
        room_id++;
        ID=room_id;
    }
	
    KRATHSH::KRATHSH(string onoma_pel, int mera, int meres_diam, int Atoma)
    {
        ID=room_id++;
        Afixh=mera;
        Onoma_Pelath=onoma_pel;
        
        // ������� ��� �������� ������ ��������
		// ���� �� ��� ��������� ��� 30 ������
        if (meres_diam+mera>30)
			Meres_Diamonhs=30-mera;
        else Meres_Diamonhs=meres_diam;
        Arithmos_atomwn=Atoma;
        Dwmatio=NULL;   
    }
    
    // ������� ������������� �������� �� �������
    void  KRATHSH::set_room(DWMATIO *R)
    { Dwmatio=R; }
    
    // ������� ��� ������ ��� �� ������ ��� ����������� ��������
    void  KRATHSH::get_Krathsh_info()
    {
        string name;
		int arr,days,Atoma;

        cout<<"Parakalw dwste onoma pelath gia thn krathsh:";
        cin >> name; fflush(stdin);
        cout<<"Dwste th mera afixhs sto xenodoheio (1-30):";
		cin>> arr;
        cout<<"Dwste tis meres diamonhs sas sto xenodoheio:";
		cin>> days;
        cout<<"Dwste ton arithmo twn atomwn:";
		cin>>Atoma;
    
        Onoma_Pelath=name;
        Afixh=arr;
		Meres_Diamonhs=days;
        Arithmos_atomwn=Atoma;
        Dwmatio=NULL;
               
    }
    
    // ������� ��������� ��� ����������� ��� ��������
    void  KRATHSH::Print()
    {
        cout<<"Onoma pelath:"<<Onoma_Pelath<<endl;
        cout<<"Hmera afixhs:"<<Afixh<<endl;
        cout<<"Hmeres diamonhs:"<<Meres_Diamonhs<<endl;
        cout<<"Atoma:"<<Arithmos_atomwn<<endl;
        if (Dwmatio!=NULL) cout<<"Arithmos dwmatiou diamonhs:"<<Dwmatio->get_ID()<<endl;
    }

	// ������� ��� ���������� �� ����� ������
	string  KRATHSH::get_Onoma_Pelath() 
	{ 
		return Onoma_Pelath;
	}

	// ������� ��� ���������� �� id
	int KRATHSH::get_ID() 
	{ 
		return ID;
	};
	
	// ������� ��� ���������� ��� ����� ������
	int KRATHSH::get_Afixh() 
	{ 
		return Afixh;
	};
	
	// ������� ��� ���������� ��� ����� ��������
	int KRATHSH::get_Meres_Diamonhs() 
	{ 
		return Meres_Diamonhs;
	};
	
	// ������� ��� ���������� ��� ������ ��� ������
	int KRATHSH::get_Arithmos_atomwn()
	{ 
		return Arithmos_atomwn;
	};
    
    // Constructor ��� ��� ����� DWMATIO
    DWMATIO::DWMATIO(int No_Atomwn, double PosoAnaAtomo)
    {
        room_id++;
        ID=room_id;
        hwrhtikothta=No_Atomwn;
        TimhAnaAtomo=PosoAnaAtomo;
        
        // ������������ ��� ������ ��������������
        for (int i=0;i<30;i++)  
        {
        	PIN_DIATH[i]=NULL;
		}
    }
    
    bool DWMATIO::Nea_Krathsh(KRATHSH *K)
	{  
	
	// ������� ��������������� ��������
	// ������� �� � ������� ������ ������� �� ������� ������������ ��������
       if(hwrhtikothta>=K->get_Arithmos_atomwn())
	   {
	   		// ������������ ����������� ���� �� ����� ��������
			for (int i=0;i<K->get_Meres_Diamonhs();i++)
			{
				//������� �� � ������� ����� ��� ���� ��� ����
				if(i+K->get_Afixh()-1<30)
				{
					// ������� �������������� ��������
					if(PIN_DIATH[i+K->get_Afixh()-1]!=NULL)
					{
						return false;
					}
				}
			}
	   }
              
   		// �������������� �������� ������ ���� ����� ������
   		// � ����������� ����� KRATHSH
		K->set_room(this);
	
		// �������� �������� ���� ������ ��������������	
		for (int i=0;i<K->get_Meres_Diamonhs();i++) 
			PIN_DIATH[i+K->get_Afixh()-1]=K;
		return true;
    }
    
    // ������� ��� ���������� ��� ���������� ��� ��������
    double DWMATIO::Timologhsh()
    {
        double sum=0;
        
       // �����������: TimhAnaAtomo * �rithmos_atomwn
        for (int i=0;i<30;i++)
        {
            if(PIN_DIATH[i]!=NULL) 
            {   
                double pr=PIN_DIATH[i]->Dwmatio->get_TimhAnaAtomo();
                double no=PIN_DIATH[i]->get_Arithmos_atomwn();
                sum+=pr*no;
            }
        }
        // ��������� ��� ��������� �����
        return sum;
    }

   // ������� ��� ������������� ��� ������� ���� ��������
   bool DWMATIO::Akurwsh(int ID_Value)
    {
		// ��������� �� ���� ��� ������ ��������������
        for (int i=0;i<30;i++)
        {
        	// ������� �� ��� ����� �����
        	if(PIN_DIATH[i]!=NULL)
        	{
        		// ������� �� � ���� (id) ��� ������ ����� ���� �� �� �������
            	if (PIN_DIATH[i]->get_ID()==ID_Value)
				{ 
                	PIN_DIATH[i]=NULL;
            	}
        	}
        }
        return true;
    }

	// ������� ��� ������� ��� ��������� ��� ��������
   double DWMATIO::Plhrothta()
   {
       int P;
       for (int i=0;i<30;i++)
       {
    		if(PIN_DIATH[i]!=NULL) 
			{
				P++; 
			}
	   }
	   return (100.0*P/30.0);
	}

	// ������� ��� ���������� �� id
	int DWMATIO::get_ID()
	{ 
		return ID;
	};
	
	// ������� ��� ���������� �� ������������ ��� ��������
	int DWMATIO::get_hwrhtikothta()
	{ 
		return hwrhtikothta;
	};
	
	// ������� ��� ���������� ��� ���� ��� �������� ��� �����
	int DWMATIO::get_TimhAnaAtomo()
	{ 
		return TimhAnaAtomo;
	};

	// ������������ ����� ��� ���� ��� �� ������� ����� �
    DWMATIO_A::DWMATIO_A(int No_Atomwn, double PosoAnaAtomo):DWMATIO(No_Atomwn,PosoAnaAtomo)
    {
         TimhAnaMera=PosoAnaAtomo;     
    }
    
    // ������� ��� ���������� ��� ���������� ��� �������� ����� �
     double DWMATIO_A::Timologhsh()
    {
        double sum=0;
        for (int i=0;i<30;i++)
        {
            if(PIN_DIATH[i]!=NULL) 
            {
				sum+=TimhAnaMera;        	
			}
        }
		return sum;
    }
    
	// ������� ��� ���������� ��� ���� ��� �����
 	int DWMATIO_A::get_TimhAnaMera() 
 	{ 
 		return TimhAnaMera;
 	};	
    
    // ������������ ����� ������� ��� ���� ��� �� ������� ����� �
    DWMATIO_B::DWMATIO_B(int No_Atomwn, double TimhAnaMera,double e): DWMATIO_A(No_Atomwn,TimhAnaMera) 
	{
        EkptwshAnaMera=e;
    }
    
	// ������� ��� ���������� ��� ���������� ��� �������� ����� �
     double  DWMATIO_B::Timologhsh()
    {
        double sum=0;
        double Ekpt=0;
        double SumEkpt=0;
        for (int i=0;i<30;i++)
        {
            if(PIN_DIATH[i]!=NULL)
            {
                Ekpt=EkptwshAnaMera;
                for (int j=0;j<PIN_DIATH[i]->get_Meres_Diamonhs();j++)
                {
                    SumEkpt+=get_TimhAnaMera()*Ekpt/100.0;
                    Ekpt+=EkptwshAnaMera;
                    
                    if(Ekpt>50)
					{
						Ekpt=50;
					}
                }
                sum+=get_TimhAnaMera()*PIN_DIATH[i]->get_Meres_Diamonhs()-SumEkpt;
			}
		}
        return sum;
    }         
     
	// ���������� ��� ������� �������� ���� �� ���������� false (������� ��� ��� �������� �������)
	bool DWMATIO_B::Akurwsh(int ID_Value)
    {
        return false;
    }

	// ������������ ����� ��������� ������ ��� ��������� ������ ��� �� ������� ����� C
	DWMATIO_C::DWMATIO_C(int No_Atomwn, double TimhAnaMera,int min_at,int min_d):DWMATIO(No_Atomwn,TimhAnaMera) 
	{
    	ElahistaAtoma=min_at;
    	ElahistesMeres=min_d;
 	}
    
    
  // ���������� ��� ������� �������� ��� ������� ����� C,
  // ����������� �� ������ �� ����������� �������
  bool DWMATIO_C::Nea_Krathsh(KRATHSH *K)
    {  
    	// ������� ��� �������� �����
        if (ElahistaAtoma>K->get_Arithmos_atomwn())
            return false;
        
		// ������� ��� ��������� ������ ��������
        if (ElahistesMeres>K->get_Meres_Diamonhs())
            return false;
     	
		// ������� ������������� ��������
        if(get_hwrhtikothta()>=K->get_Arithmos_atomwn())
		{
            for (int i=0;i<K->get_Meres_Diamonhs();i++)
            {
                if(i+K->get_Afixh()-1<30)
                {
                    if(PIN_DIATH[i+K->get_Afixh()-1]!=NULL) 
                    {
                        return false;
					}
                }
            }
		}
		
        // �������������� ��������
		K->set_room(this);
		
		for (int i=0;i<K->get_Meres_Diamonhs();i++)
		{
			PIN_DIATH[i+K->get_Afixh()-1]=K;
		}
		return true;
    }
    
    // ������� ��� ���������� �� ����� ��� �����������
    HOTEL::HOTEL(string hotelname)
    {  
		HotelName=hotelname;
	}
    
    // ������� ��� ��������� �� ��������� ������� ��� ����� ��� �����������
    void HOTEL::add_Room(DWMATIO *D1)
    {    
        Dwmatia.push_back(D1);   
    }
    
	// ������� ��� �������� ������� ������� �� ��� ������ ���
    DWMATIO* HOTEL::Search_Room(int ID_Value)
    {
    	for (int i=0;i<Dwmatia.size(); i++)
    	{
			if (Dwmatia[i]->get_ID()==ID_Value) 
			{
				return Dwmatia[i];
			}
    	}
        return NULL;
    }

  // ������� ��� �������� ������� ������� �� ��� ������ ���
  KRATHSH* HOTEL::Search_Krathsh(int ID_Value)
    {
        
        for (int i=0; i<Krathseis.size();i++)
        {
            if (Krathseis[i]->get_ID()==ID_Value)
			{
				return Krathseis[i];
			}
		}
        return NULL;
    }    
    
  // ������������ KRATHSH �� DWMATIO
  bool HOTEL::linkKrathshRoom(KRATHSH *K, int ID_Value)
  {
    DWMATIO *D;
    
    // ����� ��� ������� ������� �������� ��� ������ �������� 
    D=Search_Room(ID_Value);
    
     // ������� �� ������� �� �������
	 if(D!=NULL)
      {
      	// ������� �������������� ��������
        if(D->Nea_Krathsh(K))
        {
           Krathseis.push_back(K); 
           return true;
        }
        else
        {
            cout<<"Den pragmatopoihthhke krathsh sto dwmatio"<<ID_Value<<endl;
            return false;
        }
      }
    return false;
  }
  
	// ������� ��� ��������� ��� ������� �� ��� �������
    int HOTEL::add_Krathsh(KRATHSH *K)
    {
        for (int i=0;i<Dwmatia.size();i++)
        {
        	DWMATIO *D=Dwmatia[i];
        	
            if(D->Nea_Krathsh(K))
            {
                int ID_Value=D->get_ID();
                K->set_room(D);
                
                // �������� �������� ��� ����� ��������� �����������
                Krathseis.push_back(K);
                return ID_Value;
            }
        }
        return 0;
    }
  
  // ������� ��� �������� ��� �������
    bool HOTEL::Akurwsh(int ID_Value)
    {
        for (int i=0;i<Krathseis.size();i++)
        {   
        	KRATHSH *K=Krathseis[i];
        	
            if (K->get_ID()==ID_Value)
            {
                K->Dwmatio->Akurwsh(ID_Value);
                
                // ������ ����� �������� ���� ������ ���������
                Krathseis.erase(Krathseis.begin()+i);
                return true;
            }
        }
        return false;
    }
    
    
    // ������� ��� ���������� �� �������� ����� ��� ��������
    double HOTEL::Ypologismos_Esodwn(int ID_Value)
    {
        for (int i=0;i<Dwmatia.size();i++)
        {
        	DWMATIO *D=Dwmatia[i];
        	
            if(Dwmatia[i]->get_ID()==ID_Value)
            {
            	// ����� ������� ����������� ��� �� ������������ �������
                return D->Timologhsh();
            }
        }
        return 0;
    }
    
    
    // ������� ��� ���������� �� �������� ����� (��' ��� �� �������)
    double HOTEL::Ypologismos_Esodwn()
    {
        double sum=0;
        for (int i=0;i<Dwmatia.size();i++)
        {
            sum+=Dwmatia[i]->Timologhsh();
        }
        return sum;
    }
    
    
    // ������� ��� ��������� ��� ������ �������������� ���� ��� ��������
    void HOTEL::Print_Plano()
    {
        cout<<"Dwmatia / Hmeres";
        for (int i=0;i<30;i++)
        {
            int k=i+1;
            cout<<setw(2)<<k<<"  ";
        }
        cout<<endl;

        for (int i=0;i<Dwmatia.size();i++)
        {
            DWMATIO *D=Dwmatia[i];
            cout<<setw(15)<<D->get_ID();
			for (int j=0;j<30;j++)
            {
                if(D->PIN_DIATH[j]==NULL) cout<<"  _ ";
                else cout<<"  * ";
            }
			cout<<endl;
		}
    }
    
    
    void HOTEL::Print_Krathseis()
    {
        cout<<"Kwdikos Krathshs  Onoma Pelati Krathshs  Dwmatiou\n";
        for (int i=0;i<Krathseis.size() ;i++)
        {
            cout<<setw(16)<<Krathseis[i]->get_ID()<<setw(23)<<Krathseis[i]->get_Onoma_Pelath();
			cout<<setw(8)<<Krathseis[i]->Dwmatio->get_ID()<<endl;
		}             
    }
    
    void HOTEL::Print_Dwmatia()
    {      
        cout<<"Kwdikos Dwmatiou    Esoda   %Plhrothta\n";
        for (int i=0;i<Dwmatia.size();i++)
        {
         cout<<setw(9)<<Dwmatia[i]->get_ID()<<setw(16)<<Dwmatia[i]->Timologhsh()<<setw(13)<<Dwmatia[i]->Plhrothta()<<endl;
		}
    }


    HOTEL H("Pingo");
        
    int menu()
    {
        vector<string> Menu;
		int choice;
		
		Menu.push_back("1. Epopmenh Epanalhpsh");
		Menu.push_back("2. Prosthhkh Krathshs");
		Menu.push_back("3. Akurwsh Krathshs");
		Menu.push_back("4. Provolh Krathsewn");
		Menu.push_back("5. Provolh Dwmatiwn");
		Menu.push_back("6. Provolh Planou Krathsewn");
		Menu.push_back("7. Provolh Esodwn");
		Menu.push_back("0. Termatismos");
		
        for (int i=0;i<Menu.size();i++)  cout<<Menu[i]<<endl;
        
        cout<<endl<<endl;
        cout<<"Kante mia epilogh apo th lista grafontas ton antistoiho arithmo:"<<endl;
        cin>>choice;

        return choice;
    }
 
    void set_hotel()
    {
    	// 1�� ������ Pingo
        for (int i=0;i<2;i++)
		{
            H.add_Room(new DWMATIO(4,50));
            H.add_Room(new DWMATIO_A(5,70));
            H.add_Room(new DWMATIO_B(5,120,10));
            H.add_Room(new DWMATIO_C(5,150,4,4));
		}
		  
		DWMATIO::room_id=200;
		// 2�� ������ Pingo
		for (int i=0;i<2;i++)
		{
            H.add_Room(new DWMATIO(4,50));
            H.add_Room(new DWMATIO_A(5,70));
            H.add_Room(new DWMATIO_B(5,120,10));
            H.add_Room(new DWMATIO_C(5,150,4,4));
		}
		  
		DWMATIO::room_id=300;
		// 3�� ������ Pingo
		for (int i=0;i<2;i++)
		{
            H.add_Room(new DWMATIO(4,50));
            H.add_Room(new DWMATIO_A(5,70));
            H.add_Room(new DWMATIO_B(5,120,10));
            H.add_Room(new DWMATIO_C(5,150,4,4));
		}
    }
    
    
    
    //Main
    
    int main() {
    	string choice;
        int ID_Value;
        int j,ch;
         KRATHSH *K;
        

		set_hotel();
          
          ch=1;
          while(ch!=0){
            
            ch = menu();     
            switch(ch)
            {
            	case 0:
            		return 0;
            		break;
            		
                case 1:
                    K=new KRATHSH("AutoKrathsh ",rand()%30,rand()%10+1,rand()%6);
                    
                    H.add_Krathsh(K);
                    K->Print();
					// ���� �������� ������� ������ 25% ���������� �������� ���
					if (rand()%100<25)
                    {
                    	if(H.Krathseis.size()!=0)
						{
                        	K=H.Krathseis[rand()%H.Krathseis.size()];
                        	H.Akurwsh(K->get_ID());
						}
                    }
                	break;
    
                case 2:
                    
                    K=new KRATHSH();
                    K->get_Krathsh_info();
                    
                    cout<<"Thelete na dialexete dwmatio (y/n)? "<<endl;
                    cin>>choice; 
					fflush(stdin);
                    if(choice=="y")
                    {
                        cout<<"Arithmos dwmatiou "<<endl;
                        cin>>ID_Value;
                        
                        if(H.linkKrathshRoom(K, ID_Value))
                        {
                          cout<<"Pragmatopoihsate krathsh sto dwmatio me arithmo "<<ID_Value<<endl;
                        }
                    }
                    else
                    {
                        int ID_Value=H.add_Krathsh(K);
                        if (ID_Value!=0)
                          cout<<"Pragmatopoihsate krathsh sto dwmatio me arithmo "<<ID_Value<<endl;
                        
                    }
              
                    break;
                
                case 3:
                    cout<<"Dwste mas ton kwdiko ths krathshs sas: "<<endl; 
					cin >> ID_Value;
                    if(H.Akurwsh(ID_Value))
                	{
                        cout<<"H krathsh sas akurwthhke epituhws "<<endl;
                    }  
                	break;
                
                case 4:
                    H.Print_Krathseis();
                	break;
                    
                case 5:
                    H.Print_Dwmatia();
                	break;
                
                case 6:
                    H.Print_Plano();
                    break;
                
                case 7:
                    cout<<"Thelete na ektupwsete ta esoda kapoiou sugkekrimenou dwmatiou (y/n)?"<<endl;
                    cin>>choice;
                    
                    if(choice=="n")
                        cout<<"Esoda"<< H.Ypologismos_Esodwn()<<endl;
                    else
                    {
                        cout<<"Dwste mas ton arithmo tou dwmatiou gia to opoio thelete na deite ta esoda:"<<endl;
                        cin >> ID_Value;
                        cout<<"Ta esoda einai:"<< H.Ypologismos_Esodwn(ID_Value)<<endl;
                    }
                    break;
                    
				default:
					cout<<"Den exete eisagei eguro arithmo "<<endl;
					break;
            }   
        }       
    }
    
// .-


