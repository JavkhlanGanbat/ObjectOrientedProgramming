#include <iostream>

template<class T>
class container{ 
	private: 
		T item; 

	public: 
        T getItem() {
            return item;
        }

        void setItem(T item) {
            this->item = item;
        }
};

int main() {
    container<int> obj; 

    obj.setItem(5);
    std::cout << obj.getItem() << std::endl;

    return 0;
}
