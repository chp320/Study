package com.edu.test;

/*
import java.io.*;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;
*/
/* ���� ���� �߰� ('19.12.05) */
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/second")	// ���� ������ ���� URI�� "/second"�� ����
public class SecondServlet extends HttpServlet {
	@Override
	/* ���� ���� �߰� ('19.12.05)
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws
												ServletException, IOException {
		System.out.println("SecondServlet!!") ;
		PrintWriter out = resp.getWriter() ;
		out.print("<html><head><title>Test</title></head>");
		out.print("<body><h1>have a nice day!!</h1></body>");
		out.print("</html>");
		out.close();
	}
	*/
	protected void service(HttpServletRequest req, HttpServletResponse res) throws
													ServletException, IOException {
		System.out.println("SecondServlet!!") ;
		PrintWriter out = res.getWriter() ;
		out.print("<html><head><title>Test</title></head>");
		out.print("<body><h1>have a nice day!!</h1></body>");
		out.print("</html>");
		out.close();
	}
}
