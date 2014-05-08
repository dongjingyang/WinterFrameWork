// SmallCompoent.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SmallCompoent.h"




CSmallCompoent::CSmallCompoent()
{
	return;
}

CSmallCompoent::~CSmallCompoent()
{
	return ;
}

STDMETHODIMP CSmallCompoent::SayHelloWorld( LPCTSTR lpszSaySth )
{
	return S_OK;
}
