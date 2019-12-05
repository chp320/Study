package com.edu.test;

import javax.servlet.*;

public class FlowFilterTwo implements Filter {
	
	String charset ;
	
	/*
	 * FilterConfig ��ü���� ���� �������� ���� ��ü�� ���� �������� ����.
	 * ���� ��ü�� ���� ������ web.xml �� <filter> �±׷� �����Ǿ� ����.
	 * -> FilterConfig ��ü�� <filter> �±׿� ������ ���� ���� �� ����.
	 */
	public void init(FilterConfig config) {
		System.out.println("init() ȣ�� .......... two") ;
		
		charset = config.getInitParameter("en") ;
		
	}
	
	public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain) throws
						java.io.IOException, ServletException {
		
		/*
		 * setCharacterEncoding() �޼ҵ�� ���ڰ����� ������ �����ڵ带 ����Ͽ�
		 * Ŭ���̾�Ʈ�� ������ ��û���� ��ü(POST���)�� �ִ� ���ڿ��� ���ڵ����ִ� �޼ҵ���.
		 */ 
		req.setCharacterEncoding(charset);
		
		System.out.println("doFilter() ȣ�� �� .......... two") ;
		
		/*
		 * FilterChain ��ü�� web.xml ������ ��� <filter-mapping> �±׿� ���� ������ ������ ����
		 * ���� chain.doFilter() �޼ҵ�� chain�� ������ �ִ� ���� ��, web.xml�� ������
		 * <filter-mapping> �±׵��� ������ �ٰŷ� ��(���� ���� ���� �޼ҵ�) ������ ������ �޼ҵ带 �����ϴ� ���� ������
		 * ���� '��' ������ ������ ���Ͱ� ���� ��� ���� Ŭ���̾�Ʈ�� ��û�� ������ service() �޼ҵ带 ȣ����!
		 */
		chain.doFilter(req, res);
		System.out.println("doFilter() ȣ�� �� .......... two") ;
	}
	
	public void destroy() {
		System.out.println("destroy() ȣ�� .......... two") ;
	}
}
