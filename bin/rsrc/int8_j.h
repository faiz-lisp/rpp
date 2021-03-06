
class int8
{
	rd8 m_in;

	~int8()
	{
	}

	int8()
	{
	}

	friend int8 operator*(int8 a,int8 b)
	{
		a*=b
		return a
	}


	friend int8 operator/(int8 a,int8 b)
	{
		a/=b
		return a
	}
	
	friend bool operator<(int8 a,int8 b)
	{
		lea esi,b
		push esi
		lea esi,a
		push esi
		calle "clsb8"
		mov s_ret,eax
		add esp,8
	}

	int8(int8 a)
	{
		mov esi,this
		mov [esi],[ebp+s_off a]
		mov [esi+4],[ebp+(s_off a+4)]
	}

	int8(int8& a)
	{
		mov edi,this
		mov esi,a
		mov [edi],[esi]
		mov [edi+4],[esi+4]
	}

	int8(int a)
	{
		mov esi,this
		mov [esi],a
		mov [esi+4],0
		mov edi,a
		if(a<0)
		{
			mov esi,this
			mov [esi+4],uint::c_max
		}
	}

	int8(uint a)
	{
		mov esi,this
		mov [esi],a
		mov [esi+4],0
	}

	int toint()
	{
		mov esi,this
		mov s_ret,[esi]
	}

	rstr torstr()
	{
		rstr ret(this)
		return ret
	}

	operator=(int8 a)
	{
		mov esi,this
		mov [esi],[ebp+s_off a]
		mov [esi+4],[ebp+(s_off a+4)]
	}

	operator=(int8& a)
	{
		mov edi,this
		mov esi,a
		mov [edi],[esi]
		mov [edi+4],[esi+4]
	}

	friend operator<->(int8& a,int8& b)
	{
		c=a
		a=b
		b=c
	}

	operator+=(int8 a)
	{
		lea esi,a
		push esi
		push this
		calle "add8"
		add esp,8
	}

	operator-=(int8 a)
	{
		lea esi,a
		push esi
		push this
		calle "sub8"
		add esp,8
	}

	operator*=(int8 a)
	{
		lea esi,a
		push esi
		push this
		calle "imul8"
		add esp,8
	}
	
	operator/=(int8 a)
	{
		lea esi,a
		push esi
		push this
		calle "idiv8"
		add esp,8
	}
	
	operator%=(int8 a)
	{
		lea esi,a
		push esi
		push this
		calle "imod8"
		add esp,8
	}

	operator++()
	{
		this+=1
	}

	operator--()
	{
		this-=1
	}

	friend int8 operator+(int8 a,int8 b) 
	{
		a+=b
		return a
	}

	friend int8 operator-(int8 a,int8 b)
	{
		a-=b
		return a
	}
	
	friend int8 operator%(int8 a,int8 b)
	{
		a%=b
		return a
	}

	friend bool operator<=(int8 a,int8 b)
	{
		return a<b||a==b;
	}

	friend bool operator==(int8 a,int8 b)
	{
		cesb a,b
		if(ebx)
		{
			cesb [ebp+(s_off a+4)],[ebp+(s_off b+4)]
		}
		mov s_ret,ebx
	}

	friend bool operator!=(int8 a,int8 b)
	{
		return !(a==b)
	}

	friend bool operator>(int8 a,int8 b)
	{
		return b<a;
	}

	friend bool operator>=(int8 a,int8 b)
	{
		return b<=a;
	}
	
	friend int8 operator neg(int8 a)
	{
		return 0-a;
	}

	clear()
	{
		this=0
	}

	bool empty()
	{
		return 0==this
	}

	print()
	{
		rf.print this
	}

	printl()
	{
		rf.printl this
	}
};