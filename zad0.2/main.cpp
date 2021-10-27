#include <iostream>
class  Polygon {
private:
     int *arr;
     int size;
public:
    //голяма 4-ка
    Polygon();
    Polygon(Polygon const&);
    ~Polygon();
    Polygon& operator=(Polygon const&);

    //оператор за индексиране на върховете в многоъгълника
    int operator[] (size_t i);

    //опертор + който добавя точка в края последователността върхове на многоъгълника
    void push_back (const int& x);
    Polygon& operator+ (const int& x) ;

    //оператори за еквивалентност, които проверяват дали два многоъгълника съвпадат
    bool operator==(const Polygon& other) const;
    //оператор за изход в поток
    friend std::ostream& operator<<(std::ostream &out,Polygon data);

    //оператор (), който връща дължината на контура на многоъгълника (дължината на
    // затворената начупена линия, съставена от върховете на многоъгълника)
    void operator()(int size);

    void setSize(int size);
};


//////////////////////////////////////////////////////////////////////////
Polygon::Polygon() {
    size = 0;
    arr = nullptr;
};

Polygon::Polygon(const Polygon &other) {
this->size = other.size;
this->arr = new int[other.size];
    for (int i = 0; i < size; ++i) {
        this->arr[i] = other.arr[i];
    }
}

Polygon::~Polygon() {
delete []arr;
}

Polygon &Polygon::operator=(const Polygon & other) {
    if (this != &other) {
        delete[]arr;
        this->size = other.size;
        this->arr = new int[other.size];
        for (int i = 0; i < other.size ; ++i) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

int Polygon::operator[](size_t i) {
    return arr[i];
}
void Polygon::push_back(const int &x) {
    int *biggerBuffer = new int[size+1];
    for (size_t i = 0; i < size; ++i)
    {
        biggerBuffer[i] = arr[i];
    }
    biggerBuffer[size] = x;
    ++size;

    delete []arr;
    arr = biggerBuffer;
}
Polygon &Polygon::operator+(const int& x) {
    this->push_back(x);
    return *this;
}

bool Polygon::operator==(const Polygon& other) const {
    return this->size == other.size;
}

std::ostream &operator<<(std::ostream &out, Polygon data) {
    out<< data.arr;
    return out;
}

void Polygon::operator()(int size) {
    std::cout<<"Enter length"<<std::endl;
    double number;
    double sum = 0;
    for (int i = 0; i <size ; ++i) {
        std::cin>>number;
        sum+=number;
    }
    std::cout<<sum;
}

void Polygon::setSize(int size) {
  this->size = size;
}


int main() {
    Polygon polygon;
    int size;
    std::cin>>size;
    polygon.setSize(size);
    for (int i = 0; i <size ; ++i) {
        polygon.push_back(i);
    }

    polygon(size);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
