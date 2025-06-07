class Process {
    private:
        unsigned int processID;
        int startIndex;
    
    public:
        Process(){};
        Process(unsigned int id, int index);
        ~Process();
        void setProcessID(unsigned int processID);
        void setStartIndex(int startIndex);
        unsigned int getProcessID();
        int getStartIndex();
};