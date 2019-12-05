package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/output1")
public class Output1Servlet extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
//		res.setContentType("text/html");
		PrintWriter out = res.getWriter() ;
		out.print(req.getParameter("name"));
		out.close();
	}
}
