// Ορέστης		Αμπελικιώτης	5714
// Ευστάθιος	Κολοβός			5793
// Αντώνιος		Ψαλλίδας		5933

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <iomanip> 

using namespace std;

// Δηλώνουμε την κλάση KRATHSH πάνω από την κλάση DWMATIO,
// γιατί τη χρησιμοποιούμε σ' αυτή την κλάση.

class KRATHSH;

class DWMATIO
{  
// Μόνο για την κλάση DWMATIO
private:
	int ID;  
    int hwrhtikothta;  
    double TimhAnaAtomo;  

public:
    static int room_id; //Κωδικός Δωματίου
    // Πίνακας με pointers προς αντικείμενα τύπου KRATHSH
    KRATHSH *PIN_DIATH[30];  
 
 // Μέθοδοι
 
 // Εφαρμογή πολυμορφισμού με το keyword virtual,
 // που θα επιτρέψει στις μεθόδους των κλάσεων-παιδιών της DWMATIO
 // να εξαρτώνται απ' την πραγματική κλάση του αντικειμένου τους
 
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
   
    // Μέθοδοι
    KRATHSH(); 
    
    KRATHSH(string onoma_pel, int mera, int meres_diam, int N); 
	// Ανάθεση αντικειμένου DWMATIO στη μεταβλητή Dwmatio της κράτησης
	void set_room(DWMATIO *R);
	// Μέθοδος όπου όταν καλούμε την κλάση KRATHSH,
	// ο χρήστης να δίνει τις απαραίτητες πληροφορίες
    void get_Krathsh_info();
    // Μέθοδος που εκτυπώνει τις πληροφορίες της κράτησης
    void Print();
	
	// Μέθοδοι που επιστρέφουν τις τιμές των μεταβλητών
	int get_ID();
	int get_Afixh();
	int get_Meres_Diamonhs();
	int get_Arithmos_atomwn();
    string  get_Onoma_Pelath();
    
};

// Κλάση DWMATIO_A που κληρονομεί την κλάση DWMATIO
class DWMATIO_A : public DWMATIO
{
	private:
		double TimhAnaMera;

	public:
	// Μέθοδοι	
     DWMATIO_A(int No_Atomwn, double PosoAnaAtomo);
     double Timologhsh();
	 int get_TimhAnaMera();
	 
};

// Κλάση DWMATIO_B που κληρονομεί την κλάση DWMATIO_A
class DWMATIO_B : public DWMATIO_A
{
	private:
		double EkptwshAnaMera;

	public:
	// Μέθοδοι	
	 DWMATIO_B(int No_Atomwn, double TimhAnaMera,double Ekptwsh);
     double Timologhsh();
	 bool Akurwsh(int ID_Value);
     int get_EkptwshAnaMera(); 
};

// Κλάση DWMATIO_C που κληρονομεί την κλάση DWMATIO
class DWMATIO_C : public DWMATIO {
	
	private:
		int ElahistaAtoma;
		int ElahistesMeres;
	
    public:

// Μέθοδοι
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
 
 	// Μέθοδοι  
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


// Αρχικοποίηση μετρητών για id δωματίων και κρατήσεων

int DWMATIO::room_id=100;
int KRATHSH::room_id=1;

	// Κλήση συνάρτησης KRATHSH() μέσα απ την κλάση KRATHSH
	// που παράγει έναν κωδικό κράτησης

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
        
        // Έλεγχος των δοθέντων ημερών διαμονής
		// ώστε να μην ξεπερνούν τις 30 ημέρες
        if (meres_diam+mera>30)
			Meres_Diamonhs=30-mera;
        else Meres_Diamonhs=meres_diam;
        Arithmos_atomwn=Atoma;
        Dwmatio=NULL;   
    }
    
    // Μέθοδος αντιστοίχισης κράτησης με δωμάτιο
    void  KRATHSH::set_room(DWMATIO *R)
    { Dwmatio=R; }
    
    // Μέθοδος που ζητάει από το χρήστη τις πληροφορίες κράτησης
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
    
    // Μέθοδος εκτύπωσης των πληροφοριών της κράτησης
    void  KRATHSH::Print()
    {
        cout<<"Onoma pelath:"<<Onoma_Pelath<<endl;
        cout<<"Hmera afixhs:"<<Afixh<<endl;
        cout<<"Hmeres diamonhs:"<<Meres_Diamonhs<<endl;
        cout<<"Atoma:"<<Arithmos_atomwn<<endl;
        if (Dwmatio!=NULL) cout<<"Arithmos dwmatiou diamonhs:"<<Dwmatio->get_ID()<<endl;
    }

	// Μέθοδος που επιστρέφει το όνομα πελάτη
	string  KRATHSH::get_Onoma_Pelath() 
	{ 
		return Onoma_Pelath;
	}

	// Μέθοδος που επιστρέφει το id
	int KRATHSH::get_ID() 
	{ 
		return ID;
	};
	
	// Μέθοδος που επιστρέφει την ημέρα άφιξης
	int KRATHSH::get_Afixh() 
	{ 
		return Afixh;
	};
	
	// Μέθοδος που επιστρέφει τις μέρες διαμονής
	int KRATHSH::get_Meres_Diamonhs() 
	{ 
		return Meres_Diamonhs;
	};
	
	// Μέθοδος που επιστρέφει τον αριθμό των ατόμων
	int KRATHSH::get_Arithmos_atomwn()
	{ 
		return Arithmos_atomwn;
	};
    
    // Constructor για την κλάση DWMATIO
    DWMATIO::DWMATIO(int No_Atomwn, double PosoAnaAtomo)
    {
        room_id++;
        ID=room_id;
        hwrhtikothta=No_Atomwn;
        TimhAnaAtomo=PosoAnaAtomo;
        
        // Δημιουργούμε τον πίνακα διαθεσιμότητας
        for (int i=0;i<30;i++)  
        {
        	PIN_DIATH[i]=NULL;
		}
    }
    
    bool DWMATIO::Nea_Krathsh(KRATHSH *K)
	{  
	
	// Έλεγχος πραγματοποίησης κράτησης
	// Έλεγχος αν ο αριθμός ατόμων ξεπερνά τη μέγιστη χωρητικότητα δωματίου
       if(hwrhtikothta>=K->get_Arithmos_atomwn())
	   {
	   		// Πραγματοποιώ επαναλήψεις όσες οι μέρες διαμονής
			for (int i=0;i<K->get_Meres_Diamonhs();i++)
			{
				//Έλεγχος αν η κράτηση είναι στα όρια του μήνα
				if(i+K->get_Afixh()-1<30)
				{
					// Έλεγχος διαθεσιμότητας δωματίου
					if(PIN_DIATH[i+K->get_Afixh()-1]!=NULL)
					{
						return false;
					}
				}
			}
	   }
              
   		// Πραγματοποίηση κράτησης εφόσον αυτή είναι δυνατή
   		// Κ αντικείμενο τύπου KRATHSH
		K->set_room(this);
	
		// Προσθήκη κράτησης στον πίνακα διαθεσιμότητας	
		for (int i=0;i<K->get_Meres_Diamonhs();i++) 
			PIN_DIATH[i+K->get_Afixh()-1]=K;
		return true;
    }
    
    // Μέθοδος που επιστρέφει την τιμολόγηση των δωματίων
    double DWMATIO::Timologhsh()
    {
        double sum=0;
        
       // Υπολογισμός: TimhAnaAtomo * Αrithmos_atomwn
        for (int i=0;i<30;i++)
        {
            if(PIN_DIATH[i]!=NULL) 
            {   
                double pr=PIN_DIATH[i]->Dwmatio->get_TimhAnaAtomo();
                double no=PIN_DIATH[i]->get_Arithmos_atomwn();
                sum+=pr*no;
            }
        }
        // Επιστροφή του συνολικού ποσού
        return sum;
    }

   // Μέθοδος που πραγματοποιεί την ακύρωση μιας κράτησης
   bool DWMATIO::Akurwsh(int ID_Value)
    {
		// Αναζήτηση σε όλον τον πίνακα διαθεσιμότητας
        for (int i=0;i<30;i++)
        {
        	// Έλεγχος αν δεν είναι κενός
        	if(PIN_DIATH[i]!=NULL)
        	{
        		// Έλεγχος αν η τιμή (id) του κελιού είναι ίδια με τη δοθείσα
            	if (PIN_DIATH[i]->get_ID()==ID_Value)
				{ 
                	PIN_DIATH[i]=NULL;
            	}
        	}
        }
        return true;
    }

	// Μέθοδος που ελέγχει την πληρότητα των δωματίων
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

	// Μέθοδος που επιστρέφει το id
	int DWMATIO::get_ID()
	{ 
		return ID;
	};
	
	// Μέθοδος που επιστρέφει τη χωρητικότητα του δωματίου
	int DWMATIO::get_hwrhtikothta()
	{ 
		return hwrhtikothta;
	};
	
	// Μέθοδος που επιστρέφει την τιμή του δωματίου ανά άτομο
	int DWMATIO::get_TimhAnaAtomo()
	{ 
		return TimhAnaAtomo;
	};

	// Αρχικοποίηση τιμής ανά μέρα για τα δωμάτια τύπου Α
    DWMATIO_A::DWMATIO_A(int No_Atomwn, double PosoAnaAtomo):DWMATIO(No_Atomwn,PosoAnaAtomo)
    {
         TimhAnaMera=PosoAnaAtomo;     
    }
    
    // Μέθοδος που επιστρέφει την τιμολόγηση των δωματίων τύπου Α
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
    
	// Μέθοδος που επιστρέφει την τιμή ανά ημέρα
 	int DWMATIO_A::get_TimhAnaMera() 
 	{ 
 		return TimhAnaMera;
 	};	
    
    // Αρχικοποίηση τιμής έκπτωση ανά μέρα για τα δωμάτια τύπου Β
    DWMATIO_B::DWMATIO_B(int No_Atomwn, double TimhAnaMera,double e): DWMATIO_A(No_Atomwn,TimhAnaMera) 
	{
        EkptwshAnaMera=e;
    }
    
	// Μέθοδος που επιστρέφει την τιμολόγηση των δωματίων τύπου Β
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
     
	// Υπερκάλυψη της μεθόδου ακύρωσης ώστε να επιστρέφει false (δωμάτια που δεν δέχονται ακύρωση)
	bool DWMATIO_B::Akurwsh(int ID_Value)
    {
        return false;
    }

	// Αρχικοποίηση τιμών ελάχιστων ατόμων και ελάχιστων ημερών για τα δωμάτια τύπου C
	DWMATIO_C::DWMATIO_C(int No_Atomwn, double TimhAnaMera,int min_at,int min_d):DWMATIO(No_Atomwn,TimhAnaMera) 
	{
    	ElahistaAtoma=min_at;
    	ElahistesMeres=min_d;
 	}
    
    
  // Υπερκάλυψη την μεθόδου κράτησης στα δωμάτια τύπου C,
  // προκειμένου να γίνουν οι απαραίτητοι έλεγχοι
  bool DWMATIO_C::Nea_Krathsh(KRATHSH *K)
    {  
    	// Έλεγχος για ελάχιστα άτομα
        if (ElahistaAtoma>K->get_Arithmos_atomwn())
            return false;
        
		// Έλεγχος για ελάχιστες ημέρες διαμονής
        if (ElahistesMeres>K->get_Meres_Diamonhs())
            return false;
     	
		// Έλεγχος χωρητικότητας δωματίου
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
		
        // Πραγματοποίηση κράτησης
		K->set_room(this);
		
		for (int i=0;i<K->get_Meres_Diamonhs();i++)
		{
			PIN_DIATH[i+K->get_Afixh()-1]=K;
		}
		return true;
    }
    
    // Μέθοδος που επιστρέφει το όνομα του ξενοδοχείου
    HOTEL::HOTEL(string hotelname)
    {  
		HotelName=hotelname;
	}
    
    // Μέθοδος που προσθέτει τα καινούρια δωμάτια στο τέλος του διανύσματος
    void HOTEL::add_Room(DWMATIO *D1)
    {    
        Dwmatia.push_back(D1);   
    }
    
	// Μέθοδος που αναζητεί δωμάτιο ανάλογα με τον κωδικό του
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

  // Μέθοδος που αναζητεί κράτηση ανάλογα με τον κωδικό της
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
    
  // Αντιστοίχηση KRATHSH με DWMATIO
  bool HOTEL::linkKrathshRoom(KRATHSH *K, int ID_Value)
  {
    DWMATIO *D;
    
    // Χρήση της μεθόδου εύρεσης δωματίου από κωδικό δωματίου 
    D=Search_Room(ID_Value);
    
     // Έλεγχος αν υπάρχει το δωμάτιο
	 if(D!=NULL)
      {
      	// Έλεγχος διαθεσιμότητας δωματίου
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
  
	// Μέθοδος που προσθέτει μια κράτηση σε ένα δωμάτιο
    int HOTEL::add_Krathsh(KRATHSH *K)
    {
        for (int i=0;i<Dwmatia.size();i++)
        {
        	DWMATIO *D=Dwmatia[i];
        	
            if(D->Nea_Krathsh(K))
            {
                int ID_Value=D->get_ID();
                K->set_room(D);
                
                // Προσθήκη κράτησης στη λίστα κρατήσεων ξενοδοχείου
                Krathseis.push_back(K);
                return ID_Value;
            }
        }
        return 0;
    }
  
  // Μέθοδος που ακυρώνει μια κράτηση
    bool HOTEL::Akurwsh(int ID_Value)
    {
        for (int i=0;i<Krathseis.size();i++)
        {   
        	KRATHSH *K=Krathseis[i];
        	
            if (K->get_ID()==ID_Value)
            {
                K->Dwmatio->Akurwsh(ID_Value);
                
                // Εύρεση θέσης κράτησης στον πίνακα κρατήσεων
                Krathseis.erase(Krathseis.begin()+i);
                return true;
            }
        }
        return false;
    }
    
    
    // Μέθοδος που επιστρέφει τα συναλικά έσοδα του δωματίου
    double HOTEL::Ypologismos_Esodwn(int ID_Value)
    {
        for (int i=0;i<Dwmatia.size();i++)
        {
        	DWMATIO *D=Dwmatia[i];
        	
            if(Dwmatia[i]->get_ID()==ID_Value)
            {
            	// Χρήση μεθόδου τιμολόγησης για το συγκεκριμένο δωμάτιο
                return D->Timologhsh();
            }
        }
        return 0;
    }
    
    
    // Μέθοδος που υπολογίζει τα συνολικά έσοδα (απ' όλα τα δωμάτια)
    double HOTEL::Ypologismos_Esodwn()
    {
        double sum=0;
        for (int i=0;i<Dwmatia.size();i++)
        {
            sum+=Dwmatia[i]->Timologhsh();
        }
        return sum;
    }
    
    
    // Μέθοδος που εκτυπώνει τον πίνακα διαθεσιμότητας όλων των δωματίων
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
    	// 1ος όροφος Pingo
        for (int i=0;i<2;i++)
		{
            H.add_Room(new DWMATIO(4,50));
            H.add_Room(new DWMATIO_A(5,70));
            H.add_Room(new DWMATIO_B(5,120,10));
            H.add_Room(new DWMATIO_C(5,150,4,4));
		}
		  
		DWMATIO::room_id=200;
		// 2ος όροφος Pingo
		for (int i=0;i<2;i++)
		{
            H.add_Room(new DWMATIO(4,50));
            H.add_Room(new DWMATIO_A(5,70));
            H.add_Room(new DWMATIO_B(5,120,10));
            H.add_Room(new DWMATIO_C(5,150,4,4));
		}
		  
		DWMATIO::room_id=300;
		// 3ος όροφος Pingo
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
					// Στην αυτόματη κράτηση έχουμε 25% πιθανότητα ακύρωσής της
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


