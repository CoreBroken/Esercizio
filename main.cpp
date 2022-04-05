#include <iostream>
#include <vector>

using namespace std;
template <typename T>

class MultiSet{

private:
    vector<T> v;
public:
    explicit MultiSet(vector<T> vector){//default constructor
        this->v=vector;
    }

    void add(const T& x){
        if(typeid(this->v)==typeid(x))//check if the element is of the correct type
            cout<<"aaa"<<endl;
        this->v.push_back(x);
    }

    bool containsValue(const T& x) const {
        for(int i=0;i<this->v.size();i++){
            if(this->v.at(i)==x){
                return true;
            }

        }
        return false;

    }
    MultiSet<T> operator+( MultiSet<T> other) const{
       if(typeid(this->v)!=typeid(other.v)) {
            throw invalid_argument("retard");
       }
        vector<T> temp;
        MultiSet<T> answer(temp);

        for (T e: other.v) {
            answer.v.push_back(e);
        }
        for (T e: this->v) {
            answer.v.push_back(e);
        }
        return answer;

    }
    void remove(const T& x){
        bool found=false;
        for(int i=0;i<this->v.size();i++)
            if(this->v.at(i)==x){
                found=true;
                this->v.erase(v.begin()+i);
            }
        if(!found){
            throw "invalid_argument";
        }
    }

    int multiplicity(const T& x) const {
        int ans=0;
        for(T e: this->v)
            if(e==x){
                ans++;
            }
        return ans;
    }
    void print() const {
        for(T e: this->v)
            cout<<"|"<<e;
        cout<<endl;
    }
};
int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);

    MultiSet<int> integers(v);
    cout<<"integers: ";
    integers.print();

    integers.add(-2);
    cout<<"integers: ";
    integers.print();

    //try {
        integers.remove(2);
        cout<<"integers: ";
        integers.print();

    //}(string s)
       // cout<<s<<endl;

        if(integers.containsValue(5)){
            cout<<"contained"<<endl;
        }
        else{
            cout<<"not contained"<<endl;
        }

    integers.add(2);
    integers.add(2);

    cout<<"contained n: "<<integers.multiplicity(2)<<endl;

    vector<int> k;
    k.push_back(9);
    k.push_back(8);
    k.push_back(7);
    k.push_back(6);
    k.push_back(5);
    k.push_back(4);

    MultiSet<int> integers2(k);

    cout<<"integers: ";
    (integers+integers2).print();

    return 0;
}