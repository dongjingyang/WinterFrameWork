#include "IDComBase.h"
#ifndef DComUtility_h__
#define DComUtility_h__
namespace  UTIL
{
#define DFAILED(x) { HRESULT _h_r_ = (x); if(FAILED(_h_r_)) return _h_r_; }
#define DFAILEDV(x)	{ if(FAILED(x)) return; }
#define DFAILEDP(x, _h_r_)	{ if(FAILED(x)) return _h_r_; }
#define DFAILEDOK(x)  RFAILEDP(x, S_OK;)
#define DFAILEDESFALSE(x) RFAILEDP(x, S_FALSE;)
#define DFAILED2(x, hr) { HRESULT _h_r_ = (x); if (FAILED(_h_r_)) return _h_r_; if (hr == _h_r_) return hr; }

#define DASSERT(x, _h_r_) { if(!(x)) return _h_r_; }
#define DASSERTV(x) { if(!(x)) return; }
#define DASSERTP(x, _h_r_) { if(NULL==(x)) return _h_r_; }
#define DASSERTPV(x) RASSERTP(x, ; )
#define DTEST(x, _h_r_) { if((x)) return _h_r_; }


#define NOTIMPL { return E_NOTIMPL; }
#define NOTIMPL_ { ASSERT0; return E_NOTIMPL; }


	template<class _Ptr,
	class _Traits = default_sentry>
	struct sentry
	{
	public:
		sentry(const _Traits& tr = _Traits()) : m_tr(tr) { m_p = (_Ptr)m_tr.default_value(); }
		sentry(_Ptr p, const _Traits& tr = _Traits()) : m_p(p), m_tr(tr) {}
		~sentry() { m_tr.destroy(m_p); }
		sentry& operator = (_Ptr p) { if(!m_tr.equal_to(m_p, p)) { m_tr.destroy(m_p); m_p = p; } return *this; }
		_Ptr detach() { _Ptr tmp = m_p; m_p = (_Ptr)m_tr.default_value(); return tmp; }
		operator _Ptr () const { return m_p; }
		_Ptr operator -> () const { return m_p; }
		//	_Ptr* operator & () { return &m_p; }
	public:
		_Ptr m_p;
		_Traits m_tr;
	private:
		sentry(const sentry&);
		sentry& operator = (const sentry&);
	};


#ifndef IS_COMPILER_VC6
#ifdef WIN32
#if(_MSC_VER < 1300)
#define IS_COMPILER_VC6 1
#else
#define IS_COMPILER_VC6 0
#endif
#else
#define IS_COMPILER_VC6 0
#endif
#endif

	struct default_sentry
	{
		static void* default_value() { return 0; }
		template<class _Ptr> static bool equal_to(_Ptr l, _Ptr r) { return l == r; }
		template<class _Ptr> static void destroy(_Ptr p) { delete p; }
	};

	struct default_array_sentry
	{
		static void* default_value() { return 0; }
		template<class _Ptr> static bool equal_to(_Ptr l, _Ptr r) { return l == r; }
		template<class _Ptr> static void destroy(_Ptr p) { delete [] p; }
	};

	struct co_interface_sentry
	{
		static void* default_value() { return 0; }
		template<class _Ptr> static bool equal_to(_Ptr, _Ptr) { return false; }
		template<class _Ptr> static void destroy(_Ptr p) { if(p) p->Release(); }
	};

	template<class I>
	struct com_ptr : sentry<I*, co_interface_sentry>
	{
		typedef sentry<I*, co_interface_sentry> base;
		using base::m_p; // gcc 3.4
		// default construct:
		com_ptr() : base() {}
		// construct with:
		template<class U>
		com_ptr(const com_ptr<U>& rhs) : base() { if(rhs.m_p && FAILED(rhs.m_p->QueryInterface(de_uuidof(I), (void**)&m_p))) m_p = 0; } // gcc
#if(!IS_COMPILER_VC6)
		com_ptr(const com_ptr& rhs) : base() { if(rhs.m_p && FAILED(rhs.m_p->QueryInterface(de_uuidof(I), (void**)&m_p))) m_p = 0; } // gcc
		template<class U>
		com_ptr(const sentry<U*, co_interface_sentry>& rhs) : base() { if(rhs.m_p && FAILED(rhs.m_p->QueryInterface(de_uuidof(I), (void**)&m_p))) m_p = 0; } // gcc
#endif
		template<class U>
		com_ptr(U *p) : base() { if(p && FAILED(p->QueryInterface(de_uuidof(I), (void**)&m_p))) m_p = 0; }
		// operator =:
		template<class U>
		com_ptr& operator = (const com_ptr<U>& rhs) { if((void*)m_p != (void*)rhs.m_p) *this = rhs.m_p; return *this; }
#if(!IS_COMPILER_VC6)
		com_ptr& operator = (const com_ptr& rhs) { if(m_p != rhs.m_p) *this = rhs.m_p; return *this; }
		template<class U>
		com_ptr& operator = (const sentry<U*, co_interface_sentry>& rhs) { if((void*)m_p != (void*)rhs.m_p) *this = rhs.m_p; return *this; }
#endif
		template<class U>
		com_ptr& operator = (U *p) { if((void*)m_p == (void*)p) return *this; base::operator=(0); if(p && FAILED(p->QueryInterface(de_uuidof(I), (void**)&m_p))) m_p = 0; return *this; }
	};
}

#endif // DComUtility_h__
