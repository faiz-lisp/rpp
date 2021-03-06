#ifdef _RVM
import rfs.h
#endif

#ifdef _JIT
import rfs_j.h
#endif

#ifdef _WIN
import rfs_n.h
#endif

struct SOCKADDR
{
	ushort sin_family;
	ushort sin_port;
	int sin_addr;
	char sin_zero[8];
};

class rsock
{
	int m_socket;
	
	enum
	{
		c_invalid=(-1)//0xffffffff
	}
	
	~rsock()
	{
		close
		clear
	}
	
	rsock()
	{
		clear
	}
	
	rbool empty()
	{
		return m_socket==c_invalid
	}
	
	clear()
	{
		m_socket=c_invalid
	}

	rbool listen(int port)
	{
		m_socket=rfs.socket(2,1,0);
		if empty
			return false
		SOCKADDR addr
		addr.sin_addr=0
		addr.sin_family=2
		addr.sin_port=byterev(port.toushort)
		rfs.bind(m_socket,&addr,sizeof(SOCKADDR))
		rfs.listen(m_socket,5)
		return true
	}

	rbool accept(rsock& client)
	{
		SOCKADDR addr
		int len=sizeof(SOCKADDR)
		client.m_socket=rfs.accept(m_socket,&addr,&len)
		return client.m_socket!=c_invalid
	}
	
	close()
	{
		ifn(empty)
		{
			rfs.close(m_socket)
			clear
		}
	}
	
	//循环send
	int send(int size,const char* data)
	{
		int sendBytes=0;
		while(sendBytes<size)
		{
			int temp=rfs.send(m_socket,data+sendBytes,size-sendBytes,0);
			if (temp<=0)
			{
				return sendBytes;
			}
			elif(temp<size-sendBytes)
			{
				return sendBytes+temp;
			}
			sendBytes+=temp;
		}
		return sendBytes;
	}
	
	rbool send_s(rstr& s)
	{
		return s.count==send(s.count,s.begin)
	}
	
	//recv根据情况可能需要循环接收
	int recv(int size,char* data)
	{
		return rfs.recv(m_socket,data,size,0)
	}
	
	rstr recv_s(int max)
	{
		rstr s
		s.set_size(max)
		s.m_buf.m_count=recv(s.count,s.begin)
		return s
	}
}