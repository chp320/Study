package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/cookie1")
public class CookieTest1Servlet extends HttpServlet {
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
											ServletException, IOException{
		
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		
		Cookie c1 = new Cookie("id", "guest1") ;
		c1.setPath("/");
		res.addCookie(c1);
		
		Cookie c2 = new Cookie("code", "0001") ;
		c2.setMaxAge(60 * 60 * 3);
		c2.setPath("/");
		res.addCookie(c2);
		
		Cookie c3 = new Cookie("subject", "java") ;
		c3.setMaxAge(60 * 60 * 24 * 10);
		c3.setPath("/");
		res.addCookie(c3);
		
		out.println("쿠키 전송 완료") ;
		
		out.close();
	}
}
