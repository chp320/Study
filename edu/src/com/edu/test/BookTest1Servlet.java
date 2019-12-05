package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/bookReg")
public class BookTest1Servlet extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		req.setCharacterEncoding("UTF-8");	// ¿Ö??
		String title = req.getParameter("title") ;
		String author = req.getParameter("author") ;
		String publisher = req.getParameter("publisher") ;
		
		Book book = new Book() ;
		book.setTitle(title);
		book.setAuthor(author);
		book.setPublisher(publisher);
		
		req.setAttribute("book", book);
		
		RequestDispatcher rd = req.getRequestDispatcher("bookOutput") ;
		rd.forward(req, res);
		
		out.close();
	}
}
