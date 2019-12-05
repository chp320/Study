package com.edu.test;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;

/*
 * Filter�� implements�ϴ� ��� �ݵ�� init(), doFilter(), destroy()�� �������ؾ� ��.
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
		System.out.println("���� �ð� : " + executeTime + "ms") ;
	}
	
	public void destroy() {}
}
