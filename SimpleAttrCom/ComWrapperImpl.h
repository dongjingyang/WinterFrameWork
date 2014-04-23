
template<class T>
class CComWrapperImpl:public IWComImpl,
	public INondelegatingUnknown
{
public:
	// IUnknown
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG   __stdcall AddRef();
	virtual ULONG   __stdcall Release();

	// Constructor
	CComWrapperImpl();

	// Destructor
	~CComWrapperImpl();
protected:
private:
	CComPtr<T> spT;
	// Pointer to inner component's IUnknown
	IUnknown* m_pUnknownInner; 
};



