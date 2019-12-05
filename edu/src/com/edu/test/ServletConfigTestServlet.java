package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class ServletConfigTestServlet extends HttpServlet {
	
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		String env = this.getInitParameter("charset") ;
		req.setCharacterEncoding(env);
		out.print("<h3> ¿Ã∏ß : " + req.getParameter("name"));
		out.close();
	}

}
