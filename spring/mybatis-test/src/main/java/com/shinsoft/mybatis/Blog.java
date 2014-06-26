package com.shinsoft.mybatis;

import java.util.Date;

public class Blog {
	private int id;
	private String subject;
	private String body;
	private Date datetime;

	@Override
	public String toString() {
		return "Blog [id=" + id + ", subject=" + subject + ", body=" + body
				+ ", date=" + datetime + "]";
	}
}
