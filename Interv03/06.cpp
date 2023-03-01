//
// Created by Air on 2023/3/1.
//
// https://leetcode.cn/problems/animal-shelter-lcci/

#include "vector"
#include "iostream"
using namespace std;

class AnimalShelf {
private:
    vector<vector<int>> cat;
    vector<vector<int>> dog;
    int size;
public:
    AnimalShelf() {
        size = 0;
    }

    void enqueue(vector<int> animal) {
        if (animal[1] == 0) {
            cat.insert(cat.begin(), animal);
        } else {
            dog.insert(dog.begin(), animal);
        }
        ++size;
    }

    vector<int> dequeueAny() {
        vector<int> back = {-1, -1};
        if (!size)
            return back;
        if (!cat.empty() && (dog.empty() || (!dog.empty() && cat.back()[0] < dog.back()[0]))) { // 编号越小，"越老"
            back = cat.back();
            cat.pop_back();
        }
        else if (!dog.empty() && (cat.empty() || (!cat.empty() && dog.back()[0] < cat.back()[0]))) {
            back = dog.back();
            dog.pop_back();
        }
        --size;
        return back;
    }

    vector<int> dequeueDog() {
        vector<int> back = {-1, -1};
        if (dog.empty())
            return back;
        back = dog.back();
        dog.pop_back();
        --size;
        return back;
    }

    vector<int> dequeueCat() {
        vector<int> back = {-1, -1};
        if (cat.empty())
            return back;
        back = cat.back();
        cat.pop_back();
        --size;
        return back;
    }
};


/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */

int main() {
    AnimalShelf* obj = new AnimalShelf();
    obj->enqueue({0, 0});
    obj->enqueue({1, 1});
    obj->enqueue({2, 0});
    vector<int> param_2 = obj->dequeueAny();
    cout << param_2[0] << " " << param_2[1] << endl;
    vector<int> param_3 = obj->dequeueAny();
    cout << param_3[0] << " " << param_3[1] << endl;
//    vector<int> param_4 = obj->dequeueCat();
//    cout << param_4[0] << " " << param_4[1] << endl;
    return 0;
}