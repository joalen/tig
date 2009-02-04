static size_t utf8_length(const char **string, size_t col, int *width, size_t max_width, int *trimmed, bool reserve);
#define SCROLL_INTERVAL	1
/* Some ASCII-shorthands fitted into the ncurses namespace. */
static size_t
string_expand_length(const char *line, int tabsize)
{
	size_t size, pos;

	for (pos = 0; line[pos]; pos++) {
		if (line[pos] == '\t' && tabsize > 0)
			size += tabsize - (size % tabsize);
		else
			size++;
	}
	return size;
}

static void
string_expand(char *dst, size_t dstlen, const char *src, int tabsize)
{
	size_t size, pos;

	for (size = pos = 0; size < dstlen - 1 && src[pos]; pos++) {
		if (src[pos] == '\t') {
			size_t expanded = tabsize - (size % tabsize);

			if (expanded + size >= dstlen - 1)
				expanded = dstlen - size - 1;
			memcpy(dst + size, "        ", expanded);
			size += expanded;
		} else {
			dst[size++] = src[pos];
		}
	}

	dst[size] = 0;
}

		cmd = chomp_string(cmd + valuelen + advance);
static int
io_load(struct io *io, const char *separators,
	int (*read_property)(char *, size_t, char *, size_t))
{
	char *name;
	int state = OK;

	if (!start_io(io))
		return ERR;

	while (state == OK && (name = io_get(io, '\n', TRUE))) {
		char *value;
		size_t namelen;
		size_t valuelen;

		name = chomp_string(name);
		namelen = strcspn(name, separators);

		if (name[namelen]) {
			name[namelen] = 0;
			value = chomp_string(name + namelen + 1);
			valuelen = strlen(value);

		} else {
			value = "";
			valuelen = 0;
		}

		state = read_property(name, namelen, value, valuelen);
	}

	if (state != ERR && io_error(io))
		state = ERR;
	done_io(io);

	return state;
}

static int
run_io_load(const char **argv, const char *separators,
	    int (*read_property)(char *, size_t, char *, size_t))
{
	struct io io = {};

	return init_io_rd(&io, argv, NULL, FORMAT_NONE)
		? io_load(&io, separators, read_property) : ERR;
}

	REQ_(SCROLL_LEFT,	"Scroll two columns left"), \
	REQ_(SCROLL_RIGHT,	"Scroll two columns right"), \
LINE(AUTHOR,	   "author ",		COLOR_GREEN,	COLOR_DEFAULT,	0), \
LINE(MODE,         "",			COLOR_CYAN,	COLOR_DEFAULT,	0), \
LINE(TREE_HEAD,    "",			COLOR_DEFAULT,	COLOR_DEFAULT,	A_BOLD), \
	{ KEY_LEFT,	REQ_SCROLL_LEFT },
	{ KEY_RIGHT,	REQ_SCROLL_RIGHT },
/* Wants: object fgcolor bgcolor [attribute] */
		} else if (!string_enum_compare(argv[0], "main-author", strlen("main-author"))) {
			info = get_line_info("author");

static int parse_bool(bool *opt, const char *arg)
{
	*opt = (!strcmp(arg, "1") || !strcmp(arg, "true") || !strcmp(arg, "yes"))
		? TRUE : FALSE;
	return OK;
}

static int
parse_int(int *opt, const char *arg, int min, int max)
	int value = atoi(arg);

	if (min <= value && value <= max)
		*opt = value;
	return OK;
parse_string(char *opt, const char *arg, size_t optsize)
	int arglen = strlen(arg);
	switch (arg[0]) {
	case '\"':
	case '\'':
		if (arglen == 1 || arg[arglen - 1] != arg[0]) {
			config_msg = "Unmatched quotation";
			return ERR;
		}
		arg += 1; arglen -= 2;
	default:
		string_ncopy_do(opt, optsize, arg, strlen(arg));
		return OK;
	}
	if (!strcmp(argv[0], "show-author"))
		return parse_bool(&opt_author, argv[2]);
	if (!strcmp(argv[0], "show-date"))
		return parse_bool(&opt_date, argv[2]);
	if (!strcmp(argv[0], "show-rev-graph"))
		return parse_bool(&opt_rev_graph, argv[2]);
	if (!strcmp(argv[0], "show-refs"))
		return parse_bool(&opt_show_refs, argv[2]);
	if (!strcmp(argv[0], "show-line-numbers"))
		return parse_bool(&opt_line_number, argv[2]);
	if (!strcmp(argv[0], "line-graphics"))
		return parse_bool(&opt_line_graphics, argv[2]);
	if (!strcmp(argv[0], "line-number-interval"))
		return parse_int(&opt_num_interval, argv[2], 1, 1024);
	if (!strcmp(argv[0], "author-width"))
		return parse_int(&opt_author_cols, argv[2], 0, 1024);
	if (!strcmp(argv[0], "tab-size"))
		return parse_int(&opt_tab_size, argv[2], 1, 1024);
	if (!strcmp(argv[0], "commit-encoding"))
		return parse_string(opt_encoding, argv[2], sizeof(opt_encoding));
		warn("Error on line %d, near '%.*s': %s",
		     config_lineno, (int) optlen, opt, config_msg);
	/* It's OK that the file doesn't exist. */
	if (io_load(&io, " \t", read_option) == ERR ||
		warn("Errors while loading %s.", path);
	unsigned long yoffset;	/* Offset from the window side. */
	unsigned long p_yoffset;/* Previous offset from the window side */
	regex_t *regex;		/* Pre-compiled regexp */
	bool has_scrolled;	/* View was scrolled. */
	bool can_hscroll;	/* View can be scrolled horizontally. */
	/* Search for regexp in a line. */
	size_t skip = view->yoffset > view->col ? view->yoffset - view->col : 0;
		len = utf8_length(&string, skip, &col, max_len, &trimmed, use_tilde);
	if (len > 0)
		waddnstr(view->win, string, len);
	if (view->col + col >= view->width + view->yoffset)
		view->can_hscroll = TRUE;

	size_t skip = view->yoffset > view->col ? view->yoffset - view->col : 0;
	if (col < max && skip <= col) {
	col++;
	if (col < max && skip <= col)
		col = draw_space(view, LINE_DEFAULT, max - col, 1);
	view->col++;
	return view->width + view->yoffset <= view->col;
	view->col += draw_chars(view, type, string, view->width + view->yoffset - view->col, trim);
	size_t skip = view->yoffset > view->col ? view->yoffset - view->col : 0;
	for (i = skip; i < size; i++)
	if (size < max && skip <= size)
	view->col++;
	view->col += col;
	view->col += draw_space(view, LINE_DEFAULT, max - col, max - col);
	return view->width + view->yoffset <= view->col;
static bool
draw_author(struct view *view, const char *author)
{
	bool trim = opt_author_cols == 0 || opt_author_cols > 5 || !author;

	if (!trim) {
		static char initials[10];
		size_t pos;

#define is_initial_sep(c) (isspace(c) || ispunct(c) || (c) == '@')

		memset(initials, 0, sizeof(initials));
		for (pos = 0; *author && pos < opt_author_cols - 1; author++, pos++) {
			while (is_initial_sep(*author))
				author++;
			strncpy(&initials[pos], author, sizeof(initials) - 1 - pos);
			while (*author && !is_initial_sep(author[1]))
				author++;
		}

		author = initials;
	}

	return draw_field(view, LINE_AUTHOR, author, opt_author_cols, trim);
}

static bool
draw_mode(struct view *view, mode_t mode)
{
	static const char dir_mode[]	= "drwxr-xr-x";
	static const char link_mode[]	= "lrwxrwxrwx";
	static const char exe_mode[]	= "-rwxr-xr-x";
	static const char file_mode[]	= "-rw-r--r--";
	const char *str;

	if (S_ISDIR(mode))
		str = dir_mode;
	else if (S_ISLNK(mode))
		str = link_mode;
	else if (mode & S_IXUSR)
		str = exe_mode;
	else
		str = file_mode;

	return draw_field(view, LINE_MODE, str, sizeof(file_mode), FALSE);
}

	return view->ops->draw(view, line, lineno);
	wnoutrefresh(view->win);
	if (lineno == 0)
		view->can_hscroll = FALSE;

	wnoutrefresh(view->win);
	wnoutrefresh(view->title);
			scrollok(view->win, FALSE);
		scrollok(view->win, TRUE);
		scrollok(view->win, FALSE);
		while (line < end && draw_view_line(view, line))
			line++;
		wnoutrefresh(view->win);
	view->has_scrolled = TRUE;
	case REQ_SCROLL_LEFT:
		if (view->yoffset == 0) {
			report("Cannot scroll beyond the first column");
			return;
		}
		if (view->yoffset <= SCROLL_INTERVAL)
			view->yoffset = 0;
		else
			view->yoffset -= SCROLL_INTERVAL;
		redraw_view_from(view, 0);
		report("");
		return;
	case REQ_SCROLL_RIGHT:
		if (!view->can_hscroll) {
			report("Cannot scroll beyond the last column");
			return;
		}
		view->yoffset += SCROLL_INTERVAL;
		redraw_view(view);
		report("");
		return;
	wnoutrefresh(view->win);
			wnoutrefresh(view->win);
	view->p_yoffset = view->yoffset;
	view->yoffset = 0;
	view->yoffset = view->p_yoffset;
			if (secs > 1 && secs > view->update_secs) {
	case REQ_SCROLL_LEFT:
	case REQ_SCROLL_RIGHT:
	char text[SIZEOF_STR];
	string_expand(text, sizeof(text), line->data, opt_tab_size);
	char buf[SIZEOF_STR];
	size_t bufpos;
		for (bufpos = 0; bufpos <= req_info[i].namelen; bufpos++) {
			buf[bufpos] = tolower(req_info[i].name[bufpos]);
			if (buf[bufpos] == '_')
				buf[bufpos] = '-';
		}

		add_line_format(view, LINE_DEFAULT, "    %-25s %-20s %s",
				key, buf, req_info[i].help);
			if (!string_format_from(buf, &bufpos, "%s%s",
				keymap_table[req->keymap].name, key, buf);
	STRING_SIZE("100644 blob f931e1d229c3e185caad4449bf5b66ed72462657\t")
		if (!view->lines) {
			tree_entry(view, LINE_TREE_HEAD, opt_path, NULL, NULL);
			report("Tree is empty");
			return TRUE;
		}

	    !tree_entry(view, LINE_TREE_HEAD, opt_path, NULL, NULL))
	if (line->type == LINE_TREE_HEAD) {
		if (draw_mode(view, entry->mode))
		if (opt_author && draw_author(view, entry->author))
		/* Depending on whether it is a subdirectory or parent link
		size_t linelen = string_expand_length(line, opt_tab_size);
		if (!blame)
			return FALSE;

		string_expand(blame->text, linelen + 1, line, opt_tab_size);
	if (opt_author && draw_author(view, author))
		struct status *file = unmerged;

		} else if (!file->status || file == unmerged) {
			/* Collapse all modified entries that follow an
			 * associated unmerged entry. */
			if (unmerged == file) {
				unmerged->status = 'U';
			} else if (file->status == 'U') {
				unmerged = file;
			text = "  (no files)";
		char mode[10] = "100644";
		const char *reset_argv[] = {
			"git", "update-index", "--cacheinfo", mode,
				status->old.rev, status->old.name, NULL
		};
		string_format(mode, "%o", status->old.mode);
		return (status->status != 'U' || run_io_fg(reset_argv, opt_cdup)) &&
			run_io_fg(checkout_argv, opt_cdup);
	if (opt_author && draw_author(view, commit->author))
		string_expand(commit->title, sizeof(commit->title), line, 1);
 * NOTE: Much of the following code for dealing with Unicode is derived from
 * src/intl/charset.c from the UTF-8 branch commit elinks-0.11.0-g31f2c28.
/* Decode UTF-8 multi-byte representation into a Unicode character. */
		die("Invalid Unicode length");
utf8_length(const char **start, size_t skip, int *width, size_t max_width, int *trimmed, bool reserve)
	const char *string = *start;
		/* FIXME: Graceful handling of invalid Unicode character. */
		if (skip > 0) {
			skip -= ucwidth <= skip ? ucwidth : skip;
			*start += bytes;
		}
		last_bytes = ucwidth ? bytes : 0;
	return string - *start;
/* Terminal hacks and workarounds. */
static bool use_scroll_redrawwin;
static bool use_scroll_status_wclear;

/* Reading from the prompt? */
static bool input_mode = FALSE;

static bool status_empty = FALSE;
		if (view->has_scrolled && use_scroll_status_wclear)
			wclear(status_win);
		wnoutrefresh(status_win);
	const char *term;
	nonl();		/* Disable conversion and detect newlines from input. */
	leaveok(stdscr, FALSE);

	term = getenv("XTERM_VERSION") ? NULL : getenv("COLORTERM");
	if (term && !strcmp(term, "gnome-terminal")) {
		/* In the gnome-terminal-emulator, the message from
		 * scrolling up one line when impossible followed by
		 * scrolling down one line causes corruption of the
		 * status line. This is fixed by calling wclear. */
		use_scroll_status_wclear = TRUE;
		use_scroll_redrawwin = FALSE;

	} else if (term && !strcmp(term, "xrvt-xpm")) {
		/* No problems with full optimizations in xrvt-(unicode)
		 * and aterm. */
		use_scroll_status_wclear = use_scroll_redrawwin = FALSE;

	} else {
		/* When scrolling in (u)xterm the last line in the
		 * scrolling direction will update slowly. */
		use_scroll_redrawwin = TRUE;
		use_scroll_status_wclear = FALSE;
	}
get_input(int prompt_position)
	int i, key, cursor_y, cursor_x;
	if (prompt_position)
	while (TRUE) {
		foreach_view (view, i) {
			if (view_is_displayed(view) && view->has_scrolled &&
			    use_scroll_redrawwin)
				redrawwin(view->win);
			view->has_scrolled = FALSE;
		}

		/* Update the cursor position. */
		if (prompt_position) {
			getbegyx(status_win, cursor_y, cursor_x);
			cursor_x = prompt_position;
		} else {
			view = display[current_view];
			getbegyx(view->win, cursor_y, cursor_x);
			cursor_x = view->width - 1;
			cursor_y += view->lineno - view->offset;
		}
		setsyx(cursor_y, cursor_x);
		doupdate();
			wnoutrefresh(status_win);
			resize_display();
			redraw_display(TRUE);
		key = get_input(pos + 1);
		/* it's an annotated tag, replace the previous SHA1 with the
	return run_io_load(ls_remote_argv, "\t", read_ref);
}

static void
set_repo_config_option(char *name, char *value, int (*cmd)(int, const char **))
{
	const char *argv[SIZEOF_ARG] = { name, "=" };
	int argc = 1 + (cmd == option_set_command);
	int error = ERR;

	if (!argv_from_string(argv, &argc, value))
		config_msg = "Too many option arguments";
	else
		error = cmd(argc, argv);

	if (error == ERR)
		warn("Option 'tig.%s': %s", name, config_msg);
	if (!prefixcmp(name, "tig.color."))
		set_repo_config_option(name + 10, value, option_color_command);

	else if (!prefixcmp(name, "tig.bind."))
		set_repo_config_option(name + 9, value, option_bind_command);

	else if (!prefixcmp(name, "tig."))
		set_repo_config_option(name + 4, value, option_set_command);

	return run_io_load(config_list_argv, "=", read_repo_config_option);
	return run_io_load(rev_parse_argv, "=", read_repo_info);
static const char usage[] =
"tig " TIG_VERSION " (" __DATE__ ")\n"
"\n"
"Usage: tig        [options] [revs] [--] [paths]\n"
"   or: tig show   [options] [revs] [--] [paths]\n"
"   or: tig blame  [rev] path\n"
"   or: tig status\n"
"   or: tig <      [git command output]\n"
"\n"
"Options:\n"
"  -v, --version   Show version and exit\n"
"  -h, --help      Show help message and exit";

static enum request
parse_options(int argc, const char *argv[])
{
	enum request request = REQ_VIEW_MAIN;
	const char *subcommand;
	bool seen_dashdash = FALSE;
	/* XXX: This is vulnerable to the user overriding options
	 * required for the main view parser. */
	const char *custom_argv[SIZEOF_ARG] = {
		"git", "log", "--no-color", "--pretty=raw", "--parents",
			"--topo-order", NULL
	};
	int i, j = 6;

	if (!isatty(STDIN_FILENO)) {
		io_open(&VIEW(REQ_VIEW_PAGER)->io, "");
		return REQ_VIEW_PAGER;
	}

	if (argc <= 1)
		return REQ_NONE;

	subcommand = argv[1];
	if (!strcmp(subcommand, "status")) {
		if (argc > 2)
			warn("ignoring arguments after `%s'", subcommand);
		return REQ_VIEW_STATUS;

	} else if (!strcmp(subcommand, "blame")) {
		if (argc <= 2 || argc > 4)
			die("invalid number of options to blame\n\n%s", usage);

		i = 2;
		if (argc == 4) {
			string_ncopy(opt_ref, argv[i], strlen(argv[i]));
			i++;
		}

		string_ncopy(opt_file, argv[i], strlen(argv[i]));
		return REQ_VIEW_BLAME;

	} else if (!strcmp(subcommand, "show")) {
		request = REQ_VIEW_DIFF;

	} else {
		subcommand = NULL;
	}

	if (subcommand) {
		custom_argv[1] = subcommand;
		j = 2;
	}

	for (i = 1 + !!subcommand; i < argc; i++) {
		const char *opt = argv[i];

		if (seen_dashdash || !strcmp(opt, "--")) {
			seen_dashdash = TRUE;

		} else if (!strcmp(opt, "-v") || !strcmp(opt, "--version")) {
			printf("tig version %s\n", TIG_VERSION);
			quit(0);

		} else if (!strcmp(opt, "-h") || !strcmp(opt, "--help")) {
			printf("%s\n", usage);
			quit(0);
		}

		custom_argv[j++] = opt;
		if (j >= ARRAY_SIZE(custom_argv))
			die("command too long");
	}

	if (!prepare_update(VIEW(request), custom_argv, NULL, FORMAT_NONE))                                                                        
		die("Failed to format arguments"); 

	return request;
}

	enum request request = parse_options(argc, argv);
	if (request != REQ_NONE)
	request = request == REQ_NONE ? REQ_VIEW_MAIN : REQ_NONE;
		int key = get_input(0);
			else if (*opt_search)
				request = request == REQ_SEARCH ?
					REQ_FIND_NEXT :
					REQ_FIND_PREV;