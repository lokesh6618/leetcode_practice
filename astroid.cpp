#include <bits/stdc++.h>

using namespace std;

void printInfo(vector<int>& asteroids, int ast, int last){
    for(auto x : asteroids){
        cout << x << ", ";
    }

    cout << endl;
    cout << "Last: " << last << " current : " << ast << endl;
}

void processIncomming(vector<int>& asteroids, int ast){
    if(asteroids.size() == 0){
        asteroids.push_back(ast);
    
    }else{
        while(asteroids.size() > 0){
            int last = asteroids.back();

            if(last < 0){
                asteroids.push_back(ast);
                return;

            }else if(abs(ast) > last){
                asteroids.pop_back();

            }else if(abs(ast) < last){
                return;
            }else if(abs(ast) == last){
                asteroids.pop_back();
                return;
            }

        }
    }
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> result;

    for(auto ast : asteroids){
        if(ast > 0){
            result.push_back(ast);
        }else{
            processIncomming(result, ast);
        }
    }

    return result;
}

int main()
{
    vector<int> asteroids = {-2,-2,1,-1};

    auto result = asteroidCollision(asteroids);

    for(auto x : result){
        cout << x << ", ";
    }

    cout << endl;

    cout << "------- done ----------" << endl;
    return 0; 
}