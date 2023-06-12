class SnapShotArray {
public:
    
    int snap_id;
    
    vector<vector<pair<int, int>>> vec;
    
    SnapshotArray(int length) {
        snap_id = 0;
        
        vec.resize(length);
        
        for(int i = 0; i < length; i++) {
            
            vec[i].push_back(make_pair(0, 0));
            
        }
    }
    
    void set(int index, int val) {
        
        vec[index].push_back(make_pair(snap_id, val));
        
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        
        auto it = upper_bound(begin(vec[index]), end(vec[index]), make_pair(snap_id, INT_MAX));
        //pair(snap_id, val)
        
        return prev(it)->second;
        
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */