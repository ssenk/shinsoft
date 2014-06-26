package com.shinsoft.mybatis;

import java.io.IOException;
import java.io.InputStream;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

public class MyBatisTest {
	public static void main(String[] args) throws IOException {
		String resource = "mybatis-config.xml";
		InputStream inputStream = Resources.getResourceAsStream(resource);
		SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder()
				.build(inputStream);

		SqlSession session = sqlSessionFactory.openSession();
		try {
			Blog blog = session.selectOne(
					"org.mybatis.example.BlogMapper.selectBlog", 1);
			System.out.println(blog);
		} finally {
			session.close();
		}

	}
}
