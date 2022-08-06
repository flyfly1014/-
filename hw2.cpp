
#include <iostream>
#include <cstdlib>
using namespace std;

struct stack{
    char data;
    stack *next;
};
typedef stack* link;
link stack_big=NULL; 
link stack_small=NULL; 

void push1(char c) //大寫
{
    link newnode=(link)malloc(sizeof(stack));
    newnode->data=c; //儲存資料
    newnode->next=stack_big;//新加入的節點指向頂端
    stack_big=newnode;//新加入的節點成為頂端，指向null
}
void push2(char c) //小寫
{
    link newnode=(link)malloc(sizeof(stack));
    newnode->data=c; 
    newnode->next=stack_small;
    stack_small=newnode;
}
char pop1() //大寫
{
    link sub=stack_big;
    char temp;
    temp=sub->data;
    stack_big=stack_big->next;
    free(sub);
    return temp;
}
char pop2() //小寫
{
    link sub=stack_small;
    char temp;
    temp=sub->data;
    stack_small=stack_small->next;
    free(sub);
    return temp;
}
int check(char c) 
{ 
    if(c>='A' && c <='Z') return 1; //big
    else return 0;
}

int main()
{
    string s;
    // cout<<"The input:";
    while(cin>>s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                if(stack_big==NULL)
                    cout<<"stack big empty"<<endl;
                else 
                    cout<<pop1()<<endl;
            }
            else if(s[i]=='1')
            {
                if(stack_small==NULL)
                    cout<<"stack small empty"<<endl;
                else 
                    cout<<pop2()<<endl;
            }
            else if(s[i]=='2') //alphabetical order
            {
                char a,b;
                while(stack_big!=NULL&&stack_small!=NULL)
                {
                    a=pop1();
                    b=pop2();
                    if(check(a)==1&&check(b)==1) //都大寫
                    {
                        if(a>b) cout<<b<<a;
                        else cout<<a<<b;
                    }
                    else if(check(a)==1 && check(b)==0)//a小寫 b大寫
                    {
                        if(a+32>b) cout<<b<<a;
                        else if((a+32)==b) cout<<a<<b;
                        else cout<<a<<b;
                    }
                    else if(check(a)==0 && check(b)==1) 
                    {
                        if(a<b+32) cout<<a<<b;
                        else if((b+32)==a) cout<<b<<a;
                        else cout<<b<<a;
                    }
                    else{
                        if(a>b) cout<<b<<a;
                        else cout<<a<<b;
                    }
                    if(stack_big==NULL &&stack_small!=NULL)
                    {
                        while(stack_small)
                        {
                            b=pop2();
                            cout<<b<<endl;
                        }
                    }
                    else if(stack_small==NULL &&stack_big!=NULL)
                    {
                        while(stack_big)
                        {
                            a=pop1();
                            cout<<a<<endl;
                        }
                    }
                }
                if(stack_big==NULL && stack_small==NULL )
                    exit(0);
            }
            else if(s[i]>='A' && s[i] <='Z')
                push1(s[i]);
            else if(s[i]>='a' && s[i] <='z')
                push2(s[i]);
            else continue;
        }
    }
    return 0;
}