class NumberContainers {
public:
   unordered_map<int,int> index_number;
    unordered_map<int,set<int>> number_indices;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        //If index is already in use then remove the last number
        if(index_number.count(index)){
            number_indices[index_number[index]].erase(index);
            if(number_indices[index_number[index]].size()==0)
                number_indices.erase(index_number[index]);
        }
        
        //Insert new number
        index_number[index]=number;
        number_indices[number].insert(index);
    }
    
    int find(int number) {
        if(!number_indices.count(number))
            return -1;
        return *(number_indices[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */