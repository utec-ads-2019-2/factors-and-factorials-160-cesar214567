#include <iostream>
#include <vector>

using namespace std;

class primos{
public:
    int primo;
    int contador=0;
    primos(int primo1):primo(primo1){};
};

int main(){
    int number;
    vector<primos> primes;
    primes.push_back(2);
    for(int i=3; i < 100; i++){
        bool prime=true;
        for(int j=0;j<primes.size() && primes[j].primo*primes[j].primo <= i;j++){
            if(i % primes[j].primo == 0){
                prime=false;
                break;
            }
        }
        if(prime) {
            primes.push_back(primos(i));
        }
    }
    while (cin>>number){
        if (number==0){
            return 0;
        }else{
            for (int i=2;i<=number;i++){
                int temporal=i;
                for (int j=0;j<primes.size();j++){
                    while (temporal%primes[j].primo==0){
                        primes[j].contador+=1;
                        temporal/=primes[j].primo;
                    }
                }
            }
        }
        if (number==100){
            cout<<number<<"! =";
        }else{        
            if (number<10){
                cout<<"  "<<number<<"! =";
            }else{
                cout<<" "<<number<<"! =";
            }
        }
        for (int i=0;i<primes.size() && primes[i].primo<=number;i++){
            if (i/15>=1 && i%15==0){
                cout<<endl<<"      ";
            }
            if (primes[i].contador<10){
                cout<<"  "<<primes[i].contador;
            }else{
                cout<<" "<<primes[i].contador;
            }
            primes[i].contador=0;
        }
        cout<<endl;
    }


    return 0;
}