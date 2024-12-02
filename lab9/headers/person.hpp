class Person {
    protected:
        char* name;
        char* SSNum;
        int age;
    public: 
        void setName(const char* name);
        const char* getName();
        void setSSNum(const char* SSNum);
        const char* getSSNum();
        void setAge(int age);
        int getAge();
        Person();
        ~Person();
};