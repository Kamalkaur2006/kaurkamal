include<iostream>
using namespace std;
class Room{

     private:
		double length;
		double breadth;
		 
		 public:
		 	void get(){
		 		cout<<"Enter length:";
		 		cin>> length;
		 		cout<<"Enter breadth:";
		 		cin>> breadth;
		 	}
		 		float area() {
		 			
   return length * breadth;
}
 
 float perimeter() {
 
 
  return 2 * (length + breadth);
}
 void display(){
 	cout << "Length: " << length << endl;
    cout << "Breadth: " << breadth << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

 
 };
 int main() {
 	Room rooms[5]; 

 	for (int i = 0; i < 5; i++) {
        cout << "Room " << i + 1 << endl;
rooms[i].get();
    }

    for (int i = 0; i < 5; i++) {
        cout << "Room " << i + 1 << endl;
        rooms[i].display();
        cout << endl;
    }

    return 0;
}

