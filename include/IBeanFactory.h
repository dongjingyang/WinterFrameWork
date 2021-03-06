

#ifndef WINTER_IBEANFACTORY_H
#define WINTER_IBEANFACTORY_H

#include <string>

#ifdef WIN32
	#ifdef WINTERFRAMEWORK_EXPORTS
		#define DLL_IM_EXPORT _declspec(dllexport)
	#else
		#define DLL_IM_EXPORT _declspec(dllimport)
	#endif
#else
	#define DLL_IM_EXPORT
#endif

namespace Winter{

	/** 
	 * BeanFactory, Winter framework's interface to programmer
	 *
	 * @version 0.1.0
	 * @since 2006-12-5
	 */

	class IBeanFactory{
	private:
		/** The singleton's instance */
		//static IBeanFactory* Instance;
		
	public:
		/**
		 * Get this singleton's instance
		 * @param file Configuration XML file
		 * @return Instance of IBeanFactory
		 */
		//static IBeanFactory* getInstanceWithXML(const char* file);

		/** 
		 * Get a bean with bean's name
		 * @param basename Bean's base class name
		 * @return A pointer to the bean or to its base class
		 */
		virtual void* getBean(const std::string& name, 
			const std::string& basename = "") = 0;

		/** 
		 * Free a bean
		 * @param p A pointer to the bean
		 */
		virtual void freeBean(void* p) = 0;
		
		/** 
		 * A bean exists or not
		 * @param name Bean's name
		 * @return True if it exists, or false.
		 */
		virtual bool containsBean(const std::string& name) const = 0;

		/** 
		 * A bean is a singleton or not
		 * @param name Bean's name
		 * @return True if it's a singleton, or false.
		 */
		virtual bool isSingleton(const std::string& name) const = 0;
		
		/** 
		 * Destructor
		 */
		virtual ~IBeanFactory(){}
	};

	/** Get IBeanFactory instance */
	DLL_IM_EXPORT IBeanFactory* getBeanFactoryWithXML(const char* file);
	/** Delete IBeanFactory instance */
	DLL_IM_EXPORT void deleteBeanFactory(IBeanFactory* p);

} // End namespace Winter
#endif
