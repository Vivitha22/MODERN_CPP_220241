

#include<iostream>
#include<unordered_set>

class Employee
{
private:
    unsigned int m_id;
    std::string m_name;
    float m_salary;
    unsigned int m_age;
    float m_experence_year;
public:
    Employee()=delete;
    Employee(const Employee&)=default;
    Employee& operator = (const Employee&)=default;
    Employee(Employee&&)=default;
    Employee& operator=(Employee&&)=default;
    ~Employee()=default;

    //parameterized constructor
    Employee(unsigned int id,std::string name, float salary, unsigned int age, float years):m_id{id}, m_name{name},m_salary{salary},m_age{age},m_experence_year{years}{}
    //check applicable tax

    void CheckapplicableTax(){
        if(m_salary>0 && m_salary<=500000){
            std::cout<<"The taax amount is : "<<0.1f * m_salary<<"\n";
        }
        else if(m_salary>500000 && m_salary<=1000000){
            std::cout<<"The tax amount is : "<< 0.2f * m_salary<<"\n";
        }
        else {
            std::cout<<"Tax amount is "<< 0.3f * m_salary<<"\n";
        }
    }

    unsigned int id() const { return m_id; }

    std::string name() const { return m_name; }

    float salary() const { return m_salary; }

    unsigned int age() const { return m_age; }

    float experenceYear() const { return m_experence_year; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    

    
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "m_id: " << rhs.m_id
       << " m_name: " << rhs.m_name
       << " m_salary: " << rhs.m_salary
       << " m_age: " << rhs.m_age
       << " m_experence_year: " << rhs.m_experence_year;
    return os;
}

int main(){
    auto hash_fn = [](const Employee& e){return std::hash<unsigned int>() (e.id()); };
    auto eq_fn = [](const Employee& e1, const Employee& e2){return e1.id() == e2.id();};

    std::unordered_set<Employee, decltype(hash_fn), decltype(eq_fn)> s{3,hash_fn,eq_fn};

    s.emplace(101,"Vivitha",9000.0f,22,2.0f);
    s.emplace(101,"Kavitha", 8000.0f, 52,13.0f);
    s.emplace(102,"Vivitha",9000.0f,22,2.0f);

    for(const Employee& e :s){
        std::cout<< e <<"\n";
    }
}