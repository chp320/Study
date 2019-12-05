package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/logProc")
public class LogInOutServlet extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		String id = req.getParameter("id") ;
		String pwd = req.getParameter("pwd") ;
		
		if(id.isEmpty() || pwd.isEmpty()) {
			out.print("ID �Ǵ� ��й�ȣ�� �Է����ּ���.");
			return ;
		}
		
		HttpSession session = req.getSession() ;
		if(session.isNew() || session.getAttribute("id") == null) {
			session.setAttribute("id", id);
			out.print("�α����� �Ϸ��Ͽ����ϴ�.");
		} else {
			out.print("���� �α��� �����Դϴ�.");
		}
		out.close();
	}
	
	// �α׾ƿ� ó�� - �α׾ƿ� �� GET������� ���.
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws
												ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		// ������ ���� ��� ���� �������� ���� null�� ������.
		HttpSession session = req.getSession(false) ;
		if(session != null && session.getAttribute("id") != null) {
			session.invalidate();// ��������
			out.print("�α׾ƿ� �۾� �Ϸ��Ͽ����ϴ�.");
		} else {
			out.print("���� �α��� ���°� �ƴմϴ�.") ;
		}
		out.close();
	}
}
