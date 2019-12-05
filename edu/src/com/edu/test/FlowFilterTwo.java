package com.edu.test;

import javax.servlet.*;

public class FlowFilterTwo implements Filter {
	
	String charset ;
	
	/*
	 * FilterConfig 객체에는 현재 실행중인 필터 객체에 대한 정보값이 있음.
	 * 필터 객체에 대한 정보는 web.xml 내 <filter> 태그로 설정되어 있음.
	 * -> FilterConfig 객체는 <filter> 태그에 설정한 정보 추출 시 사용됨.
	 */
	public void init(FilterConfig config) {
		System.out.println("init() 호출 .......... two") ;
		
		charset = config.getInitParameter("en") ;
		
	}
	
	public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain) throws
						java.io.IOException, ServletException {
		
		/*
		 * setCharacterEncoding() 메소드는 인자값으로 지정된 문자코드를 사용하여
		 * 클라이언트가 전달한 요청정보 몸체(POST방식)에 있는 문자열을 인코딩해주는 메소드임.
		 */ 
		req.setCharacterEncoding(charset);
		
		System.out.println("doFilter() 호출 전 .......... two") ;
		
		/*
		 * FilterChain 객체는 web.xml 파일의 모든 <filter-mapping> 태그에 관한 정보를 가지고 있음
		 * 따라서 chain.doFilter() 메소드는 chain이 가지고 있는 정보 즉, web.xml에 설정된
		 * <filter-mapping> 태그들의 정보를 근거로 나(현재 실행 중인 메소드) 다음에 실행할 메소드를 실행하는 역할 수행함
		 * 만일 '나' 다음에 실행할 필터가 없는 경우 실제 클라이언트가 요청한 서블릿의 service() 메소드를 호출함!
		 */
		chain.doFilter(req, res);
		System.out.println("doFilter() 호출 후 .......... two") ;
	}
	
	public void destroy() {
		System.out.println("destroy() 호출 .......... two") ;
	}
}
