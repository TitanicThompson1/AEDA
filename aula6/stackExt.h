# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> ele;
    stack<T> min;
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};


template <class T> 
bool StackExt<T>::empty() const
{
    if (ele.empty())
	    return true;
    else
        return false;
}


template <class T> 
T& StackExt<T>::top()
{


    return ele.top();
}


template <class T> 
void StackExt<T>::pop()
{

    if( !min.empty() && min.top()==ele.top())
        min.pop();
    if(!ele.empty())
        ele.pop();
}


template <class T> 
void StackExt<T>::push(const T & val)
{
    ele.push(val);

    if(min.empty()){
        min.push(val);
        return;
    }

    T topo=min.top();
    if(val < topo){
        min.push(val);
    }
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    return min.top();
}

