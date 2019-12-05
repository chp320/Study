package com.edu.test;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;

/*
 * Filter를 implements하는 경우 반드시 init(), doFilter(), destroy()를 재정의해야 함.
 */
@WebFilter(filterName = "timer", urlPatterns = "/third")
public class FlowFilterThree implements Filter {
	public void init(FilterConfig config) {}
	
	public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain) throws
																	ServletException, java.io.IOException {
		long startTime = System.currentTimeMillis() ;
		
		chain.doFilter(req, res);
		
		long endTime = System.currentTimeMillis() ;
		long executeTime = endTime - startTime ;
		System.out.println("수행 시간 : " + executeTime + "ms") ;
	}
	
	public void destroy() {}
}
