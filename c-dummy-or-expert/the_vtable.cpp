struct base
{
    virtual void f();
    virtual void g();

    int a,b;
};

struct derived : base
{
    virtual void g();
    virtual void h();
    
    int c;
};

void poly(base* ptr)
{
    ptr->f();
    ptr->g();
}

int main()
{
    poly(&base());
    poly(&derived());
}
