#ifndef EASYWSCLIENT_HPP_20120819_MIOFVASDTNUASZDQPLFD
#define EASYWSCLIENT_HPP_20120819_MIOFVASDTNUASZDQPLFD

// This code comes from:
// https://github.com/dhbaird/easywsclient
//
// To get the latest version:
// wget https://raw.github.com/dhbaird/easywsclient/master/easywsclient.hpp
// wget https://raw.github.com/dhbaird/easywsclient/master/easywsclient.cpp

#include <GameSparks/gsstl.h>

#if !defined(SSL_SUPPORT)
#   define SSL_SUPPORT	//We always want SSL Support
#endif

#ifdef SSL_SUPPORT
    #include <openssl/ssl.h>
    #include <openssl/err.h>
    #include <openssl/crypto.h>
#endif

namespace easywsclient {

	bool initEasyWSClient ();
	void cleanupEasyWSClient ();

	class WebSocket {
	public:
		typedef void (*WSMessageCallback)(const gsstl::string &, void*);
		typedef WebSocket * pointer;
		typedef enum readyStateValues { CLOSING, CLOSED, CONNECTING, OPEN } readyStateValues;

		// Factories:
		static pointer create_dummy();
		static pointer from_url(const gsstl::string& url, const gsstl::string& origin = gsstl::string());
		static pointer from_url_no_mask(const gsstl::string& url, const gsstl::string& origin = gsstl::string());

		// Interfaces:
		virtual ~WebSocket() { }
		virtual void poll(int timeout = 0) = 0; // timeout in milliseconds
		virtual void send(const gsstl::string& message) = 0;
		virtual void sendPing() = 0;
		virtual void close() = 0;
		virtual readyStateValues getReadyState() const = 0;

		void dispatch(WSMessageCallback callback, void* userData) {
			_dispatch(callback, userData);
		}
        
	protected:
		struct Callback { virtual void operator()(const gsstl::string& message) = 0; };
		virtual void _dispatch(WSMessageCallback callback, void* data) = 0;
        
    protected:
        enum dnsLookup
        {
            keNone,
            keInprogress,
            keComplete,
            keFailed
        };
        
        volatile dnsLookup ipLookup;
        
        gsstl::string m_host;
        gsstl::string m_path;
        gsstl::string m_url;
        gsstl::string m_origin;
        
        int m_port;
    };

} // namespace easywsclient

#endif /* EASYWSCLIENT_HPP_20120819_MIOFVASDTNUASZDQPLFD */
