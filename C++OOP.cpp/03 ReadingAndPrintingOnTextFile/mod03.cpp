



#include<iostream>
#include<fstream>
using namespace std;


struct order{
    int id;
    char date[11];
    char employee[20];
    double total;

    bool read(istream&); 
    ostream& print(ostream&);
};

bool order::read(istream& in){ 
    total=0;
    if(in >> id >> date >> employee) {
        return true;
    }

    return false;
};

ostream& order::print(ostream&){

};

struct orderDetail{
    int order_id;
    char product[20];
    double quantity;
    double initPrice;

    bool read(istream&); 
    ostream& print(ostream&);

};

int main(){
ifstream ordersFile("orders.txt");
ifstream orderDetailsFile("ordersDetails.txt");

if(!ordersFile || orderDetailFile){
    cout << "Cannot Open files!" << endl;
    return 0;
}

ofstream resultFile("resultFile");
if(!resultFile){
    cout << "Cannot open file!" << endl;
    return 0;
}

order o;
o.read("OrderFile");

orderDetail od;
od.read("OrderDetailFile");

while(ordersFile && orderDetailsFile){
    if(o.id==od.order_id){
        o.total+=od.quantity+ od.initPrice;
        od.read(orderDetailsFile);
    }else if(order.id<od.order_id){
        o.print(resultFile);
        o.read(orderDetail)
    }else{
        od.read(orderDetailsFile);
    }
}

while(orderFile){
o.read(ordersFile);
o.print(resultFile);

}
return 0;
}
