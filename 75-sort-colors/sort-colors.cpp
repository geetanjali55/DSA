class Solution {
public:
    void sortColors(vector<int>& a) {
        int low = 0;              
    int mid = 0;               
    int high = a.size() - 1;   

   
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[mid], a[low]);
            mid++; 
            low++;  
        }
        else if (a[mid] == 1) {
            mid++;
        }
        else {
            swap(a[mid], a[high]);
            high--; 
        }
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
        }
    //     int red = 0 ;
    //     int white = 0 ;
    //     int blue = 0 ;
    //     for (int i = 0 ;i < nums.size() ;i++) {
    //         if (nums[i] == 0) {
    //             red++ ;
    //         }
    //         else if (nums[i] == 1) {
    //             white++  ;
    //         }
    //         else {
    //             blue++ ;
    //         }
    //     }
    //     for (int i = 0 ;i < red ;i++) {
    //     nums[i] = 0 ;
    // }
    // for (int i = red ;i < red + white ;i++) {
    //     nums[i] = 1 ;
    // }
    // for (int i = red + white ;i < red + white + blue ;i++) {
    //     nums[i] = 2 ;
    // }
    // for (int i = 0 ;i < nums.size() ;i++) {
    //     cout << nums[i] << endl ;
    // }
    
};