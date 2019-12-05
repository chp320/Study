package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/cookie3")
public class CookieTest3Servlet extends HttpServlet {
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws 
												ServletException, IOException {
		int cnt = 0 ;
		Cookie[] list = req.getCookies() ;
		for(int i=0; list!=null&i<list.length; i++) {
			if(list[i].getName().equals("count")) {
				cnt = Integer.parseInt(list[i].getValue()) ;
			}
		}
		
		cnt++ ;
		// === cnt+"" 에 대한 고찰.===
		// Cookie()의 value가 String타입이다. 
		// java에서는 String타입과 + 연산을 하면 String으로 변하기 때문에 
		// int형인 cnt에 +""하여 String타입으로 변경함.
		Cookie c = new Cookie("count", cnt+"") ;
		c.setMaxAge(60 * 60 * 24 * 10);
		res.addCookie(c) ;
		
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		out.print("<h1>방문 횟수 : " + cnt );
		
		out.close();
	}
}
