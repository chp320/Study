package com.edu.test;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/sessionTest")
public class SessionTestServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws 
											ServletException, IOException {
		res.setContentType("text/html;charset=UTF-8");
		PrintWriter out = res.getWriter() ;
		// Ŭ���̾�Ʈ�κ��� ���޵� ���� ���ڿ� �� 'p' ���� �����Ͽ� param ������ ����ϰڴ�!
		// ���������� p���� �̸��� ������ �ְڱ�...
		String param = req.getParameter("p") ;
		String msg = null ;
		HttpSession session = null ;
		
		// ���޵� p param���� ���� if���� ó��
		// create, delete, add, get, remove, replace�� �޳�����..
		if(param.equals("create")) {
			session = req.getSession() ;
			if(session.isNew()) {	// .isNew() : req.getSession()���� ������ ���ǰ�ü�� ���� ������ ������ ���� ���ǰ�ü���� �Ǵ�.
				msg = "���ο� ���� ��ü�� ������" ;
			} else {
				msg = "������ ���� ��ü�� ���ϵ�" ;
			}
		} else if(param.equals("delete")) {
			session = req.getSession(false) ;	// �� �̰ɾ���?? -> ���ǰ�ü�� �������� ������ null�� return.
			if(session != null) {
				session.invalidate(); // ���� ���ǰ�ü ����
				msg = "���� ��ü ���� �۾� �Ϸ�" ;
			} else {
				msg = "������ ���� �������� ����" ;
			}
		} else if(param.equals("add")) {
			session = req.getSession(true) ;	// �� �̰ɾ���?? -> ���ڰ� true.�̹Ƿ� ���ǰ�ü�� ������ �� ���� ����.
			session.setAttribute("msg", "�޽����Դϴ�.") ;
			msg = "���� ��ü�� ������ ��� �Ϸ�" ;			
		} else if(param.equals("get")) {
			session = req.getSession(false) ;	// �� �̰ɾ���??
			if(session != null) {
				String str = (String) session.getAttribute("msg") ;
				msg = str ;
			} else {
				msg = "�����͸� ������ ���� ��ü �������� ����" ;
			}
		} else if(param.equals("remove")) {
			session = req.getSession(false) ;	// �� �̰ɾ���??
			if(session != null) {
				session.removeAttribute("msg");
				msg = "���� ��ü�� ������ ���� �Ϸ�" ;
			} else {
				msg = "�����͸� ������ ���� ��ü �������� ����" ;
			}
		} else if(param.equals("replace")) {
			session = req.getSession() ;
			session.setAttribute("msg", "���ο� �޽����Դϴ�");
			msg = "���� ��ü�� ������ ��� �Ϸ�" ;
		}
		
		out.print("ó�� ��� : " + msg);
		out.close();
	}
}
