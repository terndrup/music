/* Welcome.c generated by valac 0.11.6, the Vala compiler
 * generated from Welcome.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>


#define ELEMENTARY_WIDGETS_TYPE_WELCOME (elementary_widgets_welcome_get_type ())
#define ELEMENTARY_WIDGETS_WELCOME(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ELEMENTARY_WIDGETS_TYPE_WELCOME, ElementaryWidgetsWelcome))
#define ELEMENTARY_WIDGETS_WELCOME_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ELEMENTARY_WIDGETS_TYPE_WELCOME, ElementaryWidgetsWelcomeClass))
#define ELEMENTARY_WIDGETS_IS_WELCOME(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ELEMENTARY_WIDGETS_TYPE_WELCOME))
#define ELEMENTARY_WIDGETS_IS_WELCOME_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ELEMENTARY_WIDGETS_TYPE_WELCOME))
#define ELEMENTARY_WIDGETS_WELCOME_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ELEMENTARY_WIDGETS_TYPE_WELCOME, ElementaryWidgetsWelcomeClass))

typedef struct _ElementaryWidgetsWelcome ElementaryWidgetsWelcome;
typedef struct _ElementaryWidgetsWelcomeClass ElementaryWidgetsWelcomeClass;
typedef struct _ElementaryWidgetsWelcomePrivate ElementaryWidgetsWelcomePrivate;
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Block12Data Block12Data;

struct _ElementaryWidgetsWelcome {
	GtkVBox parent_instance;
	ElementaryWidgetsWelcomePrivate * priv;
	GList* children;
	GtkVBox* options;
};

struct _ElementaryWidgetsWelcomeClass {
	GtkVBoxClass parent_class;
};

struct _Block12Data {
	int _ref_count_;
	ElementaryWidgetsWelcome * self;
	GtkButton* button;
};


static gpointer elementary_widgets_welcome_parent_class = NULL;

GType elementary_widgets_welcome_get_type (void) G_GNUC_CONST;
enum  {
	ELEMENTARY_WIDGETS_WELCOME_DUMMY_PROPERTY
};
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
ElementaryWidgetsWelcome* elementary_widgets_welcome_new (const gchar* title_text, const gchar* subtitle_text);
ElementaryWidgetsWelcome* elementary_widgets_welcome_construct (GType object_type, const gchar* title_text, const gchar* subtitle_text);
void elementary_widgets_welcome_append (ElementaryWidgetsWelcome* self, const gchar* icon_name, const gchar* label_text, const gchar* description_text);
static Block12Data* block12_data_ref (Block12Data* _data12_);
static void block12_data_unref (Block12Data* _data12_);
static gboolean _lambda10_ (Block12Data* _data12_);
static gboolean __lambda10__gtk_widget_button_release_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
static void elementary_widgets_welcome_finalize (GObject* obj);


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


ElementaryWidgetsWelcome* elementary_widgets_welcome_construct (GType object_type, const gchar* title_text, const gchar* subtitle_text) {
	ElementaryWidgetsWelcome * self = NULL;
	GtkHBox* _tmp0_ = NULL;
	GtkHBox* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	GtkLabel* _tmp4_ = NULL;
	GtkLabel* _tmp5_;
	GtkLabel* title;
	GtkLabel* _tmp6_ = NULL;
	GtkLabel* subtitle;
	GtkVBox* _tmp7_ = NULL;
	GtkVBox* _tmp8_;
	GtkHBox* _tmp9_ = NULL;
	GtkHBox* options_wrapper;
	GtkHBox* _tmp10_ = NULL;
	GtkHBox* _tmp11_;
	GtkHBox* _tmp12_ = NULL;
	GtkHBox* _tmp13_;
	GtkHBox* _tmp14_ = NULL;
	GtkHBox* _tmp15_;
	g_return_val_if_fail (title_text != NULL, NULL);
	g_return_val_if_fail (subtitle_text != NULL, NULL);
	self = (ElementaryWidgetsWelcome*) g_object_new (object_type, NULL);
	gtk_box_set_spacing ((GtkBox*) self, 5);
	gtk_box_set_homogeneous ((GtkBox*) self, FALSE);
	_tmp0_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	_tmp1_ = g_object_ref_sink (_tmp0_);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) _tmp1_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp1_);
	_tmp2_ = g_strconcat ("<span weight='heavy' size='15000'>", title_text, NULL);
	_tmp3_ = g_strconcat (_tmp2_, "</span>", NULL);
	_tmp4_ = (GtkLabel*) gtk_label_new (_tmp3_);
	title = (_tmp5_ = g_object_ref_sink (_tmp4_), _g_free0 (_tmp3_), _g_free0 (_tmp2_), _tmp5_);
	gtk_label_set_use_markup (title, TRUE);
	gtk_label_set_justify (title, GTK_JUSTIFY_CENTER);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) title, FALSE, TRUE, (guint) 0);
	_tmp6_ = (GtkLabel*) gtk_label_new (subtitle_text);
	subtitle = g_object_ref_sink (_tmp6_);
	gtk_widget_set_sensitive ((GtkWidget*) subtitle, FALSE);
	gtk_label_set_justify (subtitle, GTK_JUSTIFY_CENTER);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) subtitle, FALSE, TRUE, (guint) 6);
	_tmp7_ = (GtkVBox*) gtk_vbox_new (FALSE, 6);
	_tmp8_ = g_object_ref_sink (_tmp7_);
	_g_object_unref0 (self->options);
	self->options = _tmp8_;
	_tmp9_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	options_wrapper = g_object_ref_sink (_tmp9_);
	_tmp10_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	_tmp11_ = g_object_ref_sink (_tmp10_);
	gtk_box_pack_start ((GtkBox*) options_wrapper, (GtkWidget*) _tmp11_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp11_);
	gtk_box_pack_start ((GtkBox*) options_wrapper, (GtkWidget*) self->options, FALSE, FALSE, (guint) 0);
	_tmp12_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	_tmp13_ = g_object_ref_sink (_tmp12_);
	gtk_box_pack_end ((GtkBox*) options_wrapper, (GtkWidget*) _tmp13_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp13_);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) options_wrapper, FALSE, FALSE, (guint) 0);
	_tmp14_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	_tmp15_ = g_object_ref_sink (_tmp14_);
	gtk_box_pack_end ((GtkBox*) self, (GtkWidget*) _tmp15_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp15_);
	_g_object_unref0 (options_wrapper);
	_g_object_unref0 (subtitle);
	_g_object_unref0 (title);
	return self;
}


ElementaryWidgetsWelcome* elementary_widgets_welcome_new (const gchar* title_text, const gchar* subtitle_text) {
	return elementary_widgets_welcome_construct (ELEMENTARY_WIDGETS_TYPE_WELCOME, title_text, subtitle_text);
}


static Block12Data* block12_data_ref (Block12Data* _data12_) {
	g_atomic_int_inc (&_data12_->_ref_count_);
	return _data12_;
}


static void block12_data_unref (Block12Data* _data12_) {
	if (g_atomic_int_dec_and_test (&_data12_->_ref_count_)) {
		_g_object_unref0 (_data12_->self);
		_g_object_unref0 (_data12_->button);
		g_slice_free (Block12Data, _data12_);
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _lambda10_ (Block12Data* _data12_) {
	ElementaryWidgetsWelcome * self;
	gboolean result = FALSE;
	gint _tmp0_;
	gint index;
	self = _data12_->self;
	_tmp0_ = g_list_index (self->children, _data12_->button);
	index = _tmp0_;
	g_signal_emit_by_name (self, "activated", index);
	result = FALSE;
	return result;
}


static gboolean __lambda10__gtk_widget_button_release_event (GtkWidget* _sender, GdkEventButton* event, gpointer self) {
	gboolean result;
	result = _lambda10_ (self);
	return result;
}


void elementary_widgets_welcome_append (ElementaryWidgetsWelcome* self, const gchar* icon_name, const gchar* label_text, const gchar* description_text) {
	Block12Data* _data12_;
	GtkButton* _tmp0_ = NULL;
	GtkHBox* _tmp1_ = NULL;
	GtkHBox* hbox;
	GtkImage* _tmp2_ = NULL;
	GtkImage* icon;
	GtkVBox* _tmp3_ = NULL;
	GtkVBox* vbox;
	GtkHBox* _tmp4_ = NULL;
	GtkHBox* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	GtkLabel* _tmp8_ = NULL;
	GtkLabel* _tmp9_;
	GtkLabel* label;
	GtkLabel* _tmp10_ = NULL;
	GtkLabel* description;
	GtkHBox* _tmp11_ = NULL;
	GtkHBox* _tmp12_;
	GtkButton* _tmp13_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (icon_name != NULL);
	g_return_if_fail (label_text != NULL);
	g_return_if_fail (description_text != NULL);
	_data12_ = g_slice_new0 (Block12Data);
	_data12_->_ref_count_ = 1;
	_data12_->self = g_object_ref (self);
	_tmp0_ = (GtkButton*) gtk_button_new ();
	_data12_->button = g_object_ref_sink (_tmp0_);
	gtk_button_set_relief (_data12_->button, GTK_RELIEF_NONE);
	_tmp1_ = (GtkHBox*) gtk_hbox_new (FALSE, 6);
	hbox = g_object_ref_sink (_tmp1_);
	_tmp2_ = (GtkImage*) gtk_image_new_from_icon_name (icon_name, GTK_ICON_SIZE_DIALOG);
	icon = g_object_ref_sink (_tmp2_);
	gtk_box_pack_start ((GtkBox*) hbox, (GtkWidget*) icon, FALSE, TRUE, (guint) 6);
	_tmp3_ = (GtkVBox*) gtk_vbox_new (FALSE, 0);
	vbox = g_object_ref_sink (_tmp3_);
	_tmp4_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	_tmp5_ = g_object_ref_sink (_tmp4_);
	gtk_box_pack_start ((GtkBox*) vbox, (GtkWidget*) _tmp5_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp5_);
	_tmp6_ = g_strconcat ("<span weight='medium' size='12500'>", label_text, NULL);
	_tmp7_ = g_strconcat (_tmp6_, "</span>", NULL);
	_tmp8_ = (GtkLabel*) gtk_label_new (_tmp7_);
	label = (_tmp9_ = g_object_ref_sink (_tmp8_), _g_free0 (_tmp7_), _g_free0 (_tmp6_), _tmp9_);
	gtk_label_set_use_markup (label, TRUE);
	gtk_misc_set_alignment ((GtkMisc*) label, 0.0f, 0.5f);
	gtk_box_pack_start ((GtkBox*) vbox, (GtkWidget*) label, FALSE, FALSE, (guint) 0);
	_tmp10_ = (GtkLabel*) gtk_label_new (description_text);
	description = g_object_ref_sink (_tmp10_);
	gtk_widget_set_sensitive ((GtkWidget*) description, FALSE);
	gtk_misc_set_alignment ((GtkMisc*) description, 0.0f, 0.5f);
	gtk_box_pack_start ((GtkBox*) vbox, (GtkWidget*) description, FALSE, FALSE, (guint) 0);
	_tmp11_ = (GtkHBox*) gtk_hbox_new (FALSE, 0);
	_tmp12_ = g_object_ref_sink (_tmp11_);
	gtk_box_pack_end ((GtkBox*) vbox, (GtkWidget*) _tmp12_, TRUE, TRUE, (guint) 0);
	_g_object_unref0 (_tmp12_);
	gtk_box_pack_start ((GtkBox*) hbox, (GtkWidget*) vbox, FALSE, TRUE, (guint) 6);
	gtk_container_add ((GtkContainer*) _data12_->button, (GtkWidget*) hbox);
	_tmp13_ = _g_object_ref0 (_data12_->button);
	self->children = g_list_append (self->children, _tmp13_);
	gtk_box_pack_start ((GtkBox*) self->options, (GtkWidget*) _data12_->button, FALSE, FALSE, (guint) 0);
	g_signal_connect_data ((GtkWidget*) _data12_->button, "button-release-event", (GCallback) __lambda10__gtk_widget_button_release_event, block12_data_ref (_data12_), (GClosureNotify) block12_data_unref, 0);
	_g_object_unref0 (description);
	_g_object_unref0 (label);
	_g_object_unref0 (vbox);
	_g_object_unref0 (icon);
	_g_object_unref0 (hbox);
	block12_data_unref (_data12_);
	_data12_ = NULL;
}


static void elementary_widgets_welcome_class_init (ElementaryWidgetsWelcomeClass * klass) {
	elementary_widgets_welcome_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = elementary_widgets_welcome_finalize;
	g_signal_new ("activated", ELEMENTARY_WIDGETS_TYPE_WELCOME, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__INT, G_TYPE_NONE, 1, G_TYPE_INT);
}


static void elementary_widgets_welcome_instance_init (ElementaryWidgetsWelcome * self) {
	self->children = NULL;
}


static void elementary_widgets_welcome_finalize (GObject* obj) {
	ElementaryWidgetsWelcome * self;
	self = ELEMENTARY_WIDGETS_WELCOME (obj);
	__g_list_free__g_object_unref0_0 (self->children);
	_g_object_unref0 (self->options);
	G_OBJECT_CLASS (elementary_widgets_welcome_parent_class)->finalize (obj);
}


GType elementary_widgets_welcome_get_type (void) {
	static volatile gsize elementary_widgets_welcome_type_id__volatile = 0;
	if (g_once_init_enter (&elementary_widgets_welcome_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ElementaryWidgetsWelcomeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) elementary_widgets_welcome_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ElementaryWidgetsWelcome), 0, (GInstanceInitFunc) elementary_widgets_welcome_instance_init, NULL };
		GType elementary_widgets_welcome_type_id;
		elementary_widgets_welcome_type_id = g_type_register_static (GTK_TYPE_VBOX, "ElementaryWidgetsWelcome", &g_define_type_info, 0);
		g_once_init_leave (&elementary_widgets_welcome_type_id__volatile, elementary_widgets_welcome_type_id);
	}
	return elementary_widgets_welcome_type_id__volatile;
}



