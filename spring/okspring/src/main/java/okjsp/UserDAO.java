package okjsp;


import java.util.ArrayList;
import java.util.List;

public class UserDAO {
	// static Map<String, User> userList;
	static List<User> userList = new ArrayList<User>();

	public static void save(User user) {
		// userList.put(user.getId(), user);
		userList.add(user);
	}

	public static int size() {
		return userList.size();
	}
}
